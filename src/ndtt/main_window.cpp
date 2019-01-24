#include <member_manager.hpp>
#include "memberlist_view.hpp"
#include "main_window.hpp"

namespace ndtt {

	static constexpr int theight = 3;

	Main_window::Main_window(const std::string& title, dtt::Member_manager& manager)
	{
		int height, width;
		getmaxyx(stdscr, height, width);

		this->set_width(width);
		this->set_y(theight);
		this->set_height(height - (theight + 1));

		_titlebar = std::make_unique<Titlebar>(title, width, theight);
		_awin     = std::make_unique<Memberlist_view>(manager);
		_awin->set_y(this->y());
		_awin->set_width(width);
		_awin->set_height(this->height());

		_awin->refresh();
		_titlebar->refresh();
	}

	void Main_window::input(int c)
	{
		/* special cases */
		switch (c) {
		case 'q':
			_is_exiting = true;
			break;
		default:
			_awin->input(c);
			break;
		}
	}

	void Main_window::input(const std::string& in)
	{
	}

	void Main_window::refresh()
	{
		_awin->refresh();
	}

	bool Main_window::is_exiting() const
	{
		return _is_exiting;
	}
}
