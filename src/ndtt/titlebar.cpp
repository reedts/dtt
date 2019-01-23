#include "titlebar.hpp"

namespace ndtt {

	Titlebar::Titlebar(const std::string& title, int width, int height)
		: impl::Window {width, height, 0, 0}, _title {"-= " + title + " =-"}
	{
		wmove(_win, (this->height() / 2), (this->width() / 2 - static_cast<int>(_title.length()) / 2));
		waddstr(_win, _title.c_str());
		box(_win, 0, 0);
	}
}