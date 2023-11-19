// libraries
# include <stdio.h>
# include <ncurses.h>
# include "RotateFunc.h"

void splashscreen() {

}

void display_level(int i) {
	// Calculting Max screen dimensions
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	if (i == 1) {
	// Callind level1, if i is 1
		level1(yMax, xMax);
	} else if (i == 2) {
	// Calling level2, if i is 2
		level2(yMax, xMax);
	} else if (i == 3) {
	// Calling level3, if is 3
		level3(yMax, xMax);
	}
}

void endscreen() {
	// Calculating max screen dimensions
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	// Creating endscreen window and box
	WINDOW *endscreen = newwin(30, 80, yMax/2 - 15, xMax/2 - 40);
        refresh();
        box(endscreen, 0, 0);
        wrefresh(endscreen);
        mvwprintw(endscreen, 1, 1, "End Screen");
        wrefresh(endscreen);
}

void level1(int yMax, int xMax) {
	// Creating level1 window and box
	WINDOW *level1 = newwin(30, 80, yMax/2 - 15, xMax/2 - 40);
	refresh();
	box(level1, 0, 0);
	wrefresh(level1);
	mvwprintw(level1, 1, 1, "Level 1");
	wrefresh(level1);
}

void level2(int yMax, int xMax) {
	// Creating level2 window and box
	WINDOW *level2 = newwin(30, 80, yMax/2 - 15, xMax/2 - 40);
	refresh();
	box(level2, 0, 0);
	wrefresh(level2);
	mvwprintw(level2, 1, 1, "Level 2");
	wrefresh(level2);
}

void level3(int yMax, int xMax) {
	// Creating level3 window and box
	WINDOW *level3 = newwin(30, 80, yMax/2 - 15, xMax/2 - 40);
	refresh();
	box(level3, 0, 0);
	wrefresh(level3);
	mvwprintw(level3, 1, 1, "Level 3");
	wrefresh(level3);
}
