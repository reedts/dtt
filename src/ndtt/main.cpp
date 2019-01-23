#include <ncurses.h>
#include <vector>
#include "main_window.hpp"

int main(int argc, char* argv[])
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	refresh();
	std::unique_ptr<ndtt::Main_window> w = std::make_unique<ndtt::Main_window>("dtt v0.1");
	w->refresh();


	while (true) {
		int c = getch();

		w->input({static_cast<char>(c)});

		if (w->is_exiting()) {
			break;
		} else {
			w->refresh();
		}
	}

	endwin();

	return 0;
}
