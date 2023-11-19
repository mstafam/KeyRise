// libraries
# include <stdio.h>
# include <stdlib.h>
# include <ncurses.h>
# include "RotateFunc.h"
# include <string.h>


void how_to_play() {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *howWin = newwin(30, 80, (yMax - 30) / 2, (xMax - 80) / 2);
    box(howWin, 0, 0);
    
    // Add your instructions here
    mvwprintw(howWin, 1, 1, "How to Play:");
    mvwprintw(howWin, 3, 1, "1. Use the arrow keys to navigate");
    mvwprintw(howWin, 4, 1, "2. Use spacebar to jump");
    mvwprintw(howWin, 5, 1, "3. Collect all keys to win");
    mvwprintw(howWin, 6, 1, "4. Beware! The map will rotate every few seconds and rotate faster over time");
    mvwprintw(howWin, 8, 1, "Press any key to return to menu");

    // Display the window with instructions
    wrefresh(howWin);

    // Wait for a key press to close the instructions
    wgetch(howWin);
    delwin(howWin);
}

void splashscreen() {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);

    WINDOW *splash = newwin(30, 80, (yMax - 30) / 2, (xMax - 80) / 2);
    keypad(splash, true); // Enable keyboard input for the window
    wbkgd(splash, COLOR_PAIR(1)); 
    box(splash, 0, 0); 

    char *choices[] = {"Play", "How to Play", "Exit"};
    int choice;
    int highlight = 0;

    while(1) {
        for(int i = 0; i < 3; ++i) {
            if(i == highlight)
                wattron(splash, A_REVERSE); // Highlight the selected item
            else
                wattron(splash, COLOR_PAIR(2)); // Apply white color to text
            
            mvwprintw(splash, 9 + i * 2, (80 - strlen(choices[i])) / 2, "%s", choices[i]);
            wattroff(splash, COLOR_PAIR(2)); // Turn off white color for other items
            wattroff(splash, A_REVERSE); // Turn off highlight
        }
        wrefresh(splash);

        choice = wgetch(splash); // Get user input

        switch(choice) {
            case KEY_UP:
                highlight = highlight > 0 ? highlight - 1 : 2;
                break;
            case KEY_DOWN:
                highlight = highlight < 2 ? highlight + 1 : 0;
                break;
            case 10: // Enter key
                if (highlight == 1) { // If "How to Play" is selected
                    how_to_play(); // Call the function to display the instructions
                    // Redraw the splash screen after returning from the instructions
                    wbkgd(splash, COLOR_PAIR(1)); 
                    box(splash, 0, 0); 
                    wrefresh(splash);
                } else if (highlight == 2) { // If "Exit" is selected
                    delwin(splash);
                    endwin(); // End curses mode
                    exit(0); // Terminate the program
                }
                break;
        }
    }
    // Cleanup
    delwin(splash);
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
