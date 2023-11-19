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
	getch();
	display_level(levelOne);
	getch();
	// Calling level two
	display_level(levelTwo);
	getch();
	// Calling level three
	display_level(levelThree);
	getch();
	// Calling the endscreen
	endscreen();
	getch();
	// Closing window
	endwin();
	// Return 0
	return 0;
}
