#include "main_window.hpp"
#include <iostream>

namespace ndtt {

	static constexpr int theight = 3;

	Main_window::Main_window(const std::string& title)
	{
		int height, width;
		getmaxyx(stdscr, height, width);

		this->set_width(width);
		this->set_y(theight + 1);
		this->set_height(height - (theight + 1));

		_titlebar = std::make_unique<Titlebar>(title, width, theight);
		_titlebar->refresh();
	}

	void Main_window::input(const std::string& in)
	{
		/* special cases */
		switch (in[0]) {
		case 'q':
			_is_exiting = true;
			break;
		default:
			break;
		}

	}

	void Main_window::refresh()
	{
		impl::Window::refresh();
	}

	bool Main_window::is_exiting() const
	{
		return _is_exiting;
	}
}
