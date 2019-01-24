#include <ncurses.h>
#include <vector>
#include <member_manager.hpp>
#include "main_window.hpp"

int main(int argc, char* argv[])
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	dtt::Member_manager manager;

	manager.add_member("Hugo Müller", "hujo", "hugo@unimuenster.de", 406441);
	manager.add_member("Anna Habicht", "habi", "habicht@unimuenster.de", 406451);
	manager.add_member("Schwanz Lutscher", "lutschi", "lutschi@unimuenster.de", 406461);

	refresh();
	std::unique_ptr<ndtt::Main_window> w = std::make_unique<ndtt::Main_window>("dtt v0.1", manager);
	w->refresh();


	while (true) {
		int c = getch();

		w->input(c);

		if (w->is_exiting()) {
			break;
		} else {
			w->refresh();
		}
	}

	endwin();

	return 0;
}
