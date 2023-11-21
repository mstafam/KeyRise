/*
 * Names: Mustafa Mohamed, Sami Elsayed
 * Lab: 9-11
 */

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
	// Initializing ncurses
	initscr();
	curs_set(0);
	// Enabling color
	start_color();
	// Calling splashscreen
	splashscreen();
	clear();
	refresh();
	// Calling level one
	display_level(levelOne);
	getch();
	clear();
	refresh();
	// Calling level two
	display_level(levelTwo);
	getch();
	clear();
	refresh();
	// Calling level three
	display_level(levelThree);
	getch();
	clear();
	refresh();
	// Calling the endscreen
	endscreen();
	getch();
	clear();
	refresh();
	// Return 0
	return 0;
}
