#pragma once

#include <ncurses.h>
#include <string>

namespace ndtt {

	class Main_window {
	public:
		Main_window(const std::string& title);
		~Main_window();

		void input(const std::string& in);

		void refresh();

		bool is_exiting() const;

	private:

		bool _is_exiting {false};
		int _width;
		int _height;
		WINDOW* _win;
	};
}