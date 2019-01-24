#include "list_view.hpp"

namespace ndtt {
	namespace impl {

		List_view::List_view(const std::vector<std::string>& cols, std::size_t size, int width, int height, int x, int y)
			: Window {width, height, x , y}, _num_cols {static_cast<int>(cols.size())}, _size {size}, _cols {cols}
		{

		}

		List_view::List_view(std::vector<std::string>&& cols, std::size_t size, int width, int height, int x, int y)
			: Window {width, height, x, y}, _num_cols {static_cast<int>(cols.size())}, _size {size}, _cols {cols}
		{

		}

		void List_view::input(int c)
		{
			switch (c) {
			case KEY_DOWN: {
				select(_sel_idx + 1);
				break;
			}
			case KEY_UP:
				select(_sel_idx - 1);
				break;
			default:
				break;
			}
		}

		void List_view::refresh()
		{
			draw_labels();
			Window::refresh();
		}

		void List_view::select(int pos)
		{
			/* cap new pos into list range */
			int npos = std::max(0, std::min(pos, static_cast<int>(_size) - 1));
			if (npos != _sel_idx) {
				dehighlight_line(_sel_idx);
				highlight_line(npos);
				_sel_idx = npos;
			}
		}

		int List_view::get_selection() const
		{
			return _sel_idx;
		}

		void List_view::set_size(std::size_t size)
		{
			_size = size;
		}

		void List_view::highlight_line(int pos)
		{
			mvwchgat(_win, this->y() + padding_top + pos, this->x() + padding_left,
			         this->width() - (padding_left + padding_right), A_REVERSE, 0, NULL);
		}

		void List_view::dehighlight_line(int pos)
		{
			mvwchgat(_win, this->y() + padding_top + pos, this->x() + padding_left,
			         this->width() - (padding_left + padding_right), A_NORMAL, 0, NULL);
		}

		void List_view::draw_labels()
		{
			wattron(_win, A_BOLD);
			int cols_size = this->width() / _num_cols;
			int i = 0;
			for (const auto& label : _cols) {
				mvwaddstr(_win, this->y(), this->x() + padding_left + i * cols_size, label.c_str());
				++i;
			}
			wattroff(_win, A_BOLD);
		}
	}
}