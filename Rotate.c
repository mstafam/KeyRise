# include <stdio.h>
# include <ncurses.h>
# include "RotateFunc.h"


int main() {
	int levelOne = 1;
	int levelTwo = 2;
	int levelThree = 3;

	initscr();
	getch();
	printw("Hello World");
	splashscreen();
	display_level(levelOne);
	display_level(levelTwo);
	display_level(levelThree);
	endscreen();
	return 0;
}
