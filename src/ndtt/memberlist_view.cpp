#include <member.hpp>
#include <member_manager.hpp>

#include "memberlist_view.hpp"

namespace ndtt {

	Memberlist_view::Memberlist_view(dtt::Member_manager& manager)
		: _cols {"UID", "Matnr", "Username", "Name", "Mailaddress"}, _manager {manager}
	{
	}

	void Memberlist_view::input(int c)
	{
		switch (c) {
		case KEY_DOWN: {
			/* Clear old marking */
			dehighlight_line(_sel_idx);
			_sel_idx = _sel_idx + 1 >= _manager.size() ? _sel_idx : _sel_idx + 1;
			break;
		}
		case KEY_UP:
			/* Clear old marking */
			dehighlight_line(_sel_idx);
			_sel_idx = _sel_idx - 1 < 0 ? _sel_idx : _sel_idx - 1;
			break;
		default:
			break;
		}
	}

	void Memberlist_view::input(const std::string& in)
	{
	}

	void Memberlist_view::refresh()
	{
		box(_win, 0, 0);
		std::uint32_t i = 0;
		draw_labels();

		for (const auto& m : _manager) {
			draw_line(m.second, i);
			++i;
		}

		impl::Window::refresh();
	}

	void Memberlist_view::draw_labels()
	{
		wattron(_win, A_BOLD);
		int cols_size = this->width() / cols;
		int i = 0;
		for (const auto& label : _cols) {
			mvwaddstr(_win, this->y(), this->x() + padding_left + i * cols_size, label.c_str());
			++i;
		}
		wattroff(_win, A_BOLD);
	}

	void Memberlist_view::draw_line(const dtt::Member& m, int pos)
	{
		int cols_size = this->width() / cols;
		mvwaddstr(_win, this->y() + padding_top + pos, this->x() + padding_left, std::to_string(m.uid()).c_str());
		mvwaddstr(_win, this->y() + padding_top + pos, this->x() + padding_left + cols_size,
			      std::to_string(m.matnr()).c_str());
		mvwaddstr(_win, this->y() + padding_top + pos, this->x() + padding_left + 2 * cols_size, m.uname().c_str());
		mvwaddstr(_win, this->y() + padding_top + pos, this->x() + padding_left + 3 * cols_size, m.name().c_str());
		mvwaddstr(_win, this->y() + padding_top + pos, this->x() + padding_left + 4 * cols_size,
			      m.mail_address().c_str());

		if (pos == _sel_idx) {
			highlight_line(pos);
		}
	}

	void Memberlist_view::highlight_line(int pos)
	{
		mvwchgat(_win, this->y() + padding_top + pos, this->x() + padding_left,
			this->width() - (padding_left + padding_right), A_REVERSE, 0, NULL);
	}

	void Memberlist_view::dehighlight_line(int pos)
	{
		mvwchgat(_win, this->y() + padding_top + pos, this->x() + padding_left,
			this->width() - (padding_left + padding_right), A_NORMAL, 0, NULL);
	}
}
