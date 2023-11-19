# include <stdio.h>
# include <ncurses.h>
# include "RotateFunc.h"

int main() {
	int levelOne = 1;
	int levelTwo = 2;
	int levelThree = 3;
	initscr();
	splashscreen();
	getch();
	display_level(levelOne);
	getch();
	display_level(levelTwo);
	getch();
	display_level(levelThree);
	getch();
	endwin();
	return 0;
}
