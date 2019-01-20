#include "main_window.hpp"

namespace ndtt {

	Main_window::Main_window(const std::string& title)
	{
		getmaxyx(stdscr, _height, _width);
		_win = newwin(_height, _width, 0, 0);
	}

	Main_window::~Main_window()
	{
		delwin(_win);
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
		wrefresh(_win);
	}

	bool Main_window::is_exiting() const
	{
		return _is_exiting;
	}
}
