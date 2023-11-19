# include <stdio.h>
# include <ncurses.h>
# include "RotateFunc.h"

void splashscreen() {

}

void display_level(int i) {
	if (i == 1) {
		level1();
	} else if (i == 2) {
		level2();
	} else if (i == 3) {
		level3();
	}
}

void endscreen() {
	WINDOW *endscreen = newwin(30, 30, 0, 0);
        refresh();
        box(endscreen, '|', '-');
        wrefresh(endscreen);
        mvwprintw(endscreen, 1, 1, "End Screen");
        wrefresh(endscreen);
}

void level1() {
	WINDOW *level1 = newwin(30, 30, 0, 0);
	refresh();
	box(level1, '|', '-');
	wrefresh(level1);
	mvwprintw(level1, 1, 1, "Level 1");
	wrefresh(level1);
}

void level2() {
	WINDOW *level2 = newwin(30, 30, 0,0);
	refresh();
	box(level2, '|', '-');
	wrefresh(level2);
	mvwprintw(level2, 1, 1, "Level 2");
	wrefresh(level2);
}

void level3() {
	WINDOW *level3 = newwin(30, 30, 0,0);
	refresh();
	box(level3, '|', '-');
	wrefresh(level3);
	mvwprintw(level3, 1, 1, "Level 3");
	wrefresh(level3);
}
