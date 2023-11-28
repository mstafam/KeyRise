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
	// Initialization
	initscr(); noecho(); cbreak();
	curs_set(0);
	// Enabling color
	start_color();
	// Calling splash screen
	splashscreen();
	// Calling level one
	display_level(1);
	// Calling level two
	display_level(2);
	// Calling level three
	display_level(3);
	// Calling the endscreen
	endscreen();
	// Return 0
	return 0;
}
