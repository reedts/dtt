#include <member.hpp>
#include <member_manager.hpp>

#include "memberlist_view.hpp"

namespace ndtt {

	Memberlist_view::Memberlist_view(dtt::Member_manager& manager, int width, int height, int x, int y)
		: impl::List_view {{"UID", "Matnr", "Username", "Name", "Mailaddress"}, manager.size(), width, height, x, y}
		, _manager {manager}
	{
	}

	void Memberlist_view::input(int c)
	{
		impl::List_view::input(c);
	}

	void Memberlist_view::input(const std::string& in)
	{
	}

	void Memberlist_view::refresh()
	{
		box(_win, 0, 0);
		std::uint32_t i = 0;

		for (const auto& m : _manager) {
			draw_line(m.second, i);
			++i;
		}

		impl::List_view::refresh();
		/* if we have an active dialog refresh it after the rest of the window */
		if (_adialog) {
			_adialog->refresh();
		}
	}

	void Memberlist_view::draw_line(const dtt::Member& m, int pos)
	{
		int cols_size = this->width() / _num_cols;
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

	void Memberlist_view::open_add_dialog()
	{

	}
}
