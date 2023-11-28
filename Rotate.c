// libraries
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <ncurses.h>
# include "RotateFunc.h"

int main() {
	// Creating level variables
	int levelOne = 1;
	int levelTwo = 2;
	int levelThree = 3;
	int curWindow = 0;
	int yMax, xMax;

  getmaxyx(stdscr, yMax, xMax);

	initscr();

	WINDOW *gameWindow = newwin(30, 80, (yMax - 30) / 2, (xMax - 80) / 2);
	box(gameWindow, 0, 0);

	curs_set(0);
	start_color();
	curWindow++;
	splashscreen();
	clear();
	refresh();
	curWindow++;
	display_level(levelOne);
	getchar();
	clear();
	refresh();
	// Calling level two
	curWindow++;
	display_level(levelTwo);
	getchar();
	clear();
	refresh();
	// Calling level three
	curWindow++;
	display_level(levelThree);
	getchar();
	clear();
	refresh();
	// Calling the endscreen
	curWindow++;
	endscreen();
	getchar();
	clear();
	refresh();
	// Return 0
	return 0;
}
