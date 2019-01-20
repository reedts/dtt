#include <ncurses.h>
#include <vector>
#include "main_window.hpp"

int main(int argc, char* argv[])
{
	initscr();
	raw();
	noecho();
	ndtt::Main_window w {"Test"};

	while (true) {
		int c = getch();

		w.input({static_cast<char>(c)});

		if (w.is_exiting()) {
			break;
		} else {
			w.refresh();
		}
	}

	endwin();

	return 0;
}
