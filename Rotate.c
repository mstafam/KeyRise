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
	
	initscr();
	start_color();
	splashscreen();
	clear();
	refresh();
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
