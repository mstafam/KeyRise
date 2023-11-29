/*
 * Names: Mustafa Mohamed, Sami Elsayed
 * Lab: 9-11
 */

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "RotateFunc.h"
#include <string.h>
#include <unistd.h>
#include <time.h>

void how_to_play() {
    clear();
    int yMax, xMax;
    // Fetch the maximum screen dimensions
    getmaxyx(stdscr, yMax, xMax);

    // Define a blue color pair
    init_pair(1, COLOR_BLUE, COLOR_BLACK);

    // Create a new window for the 'How to Play' screen
    WINDOW *howWin = newwin(30, 80, (yMax - 30) / 2, (xMax - 80) / 2);
    // Apply the color pair to the window's border
    wattron(howWin, COLOR_PAIR(1));
    box(howWin, 0, 0); // Draw the border
    wattroff(howWin, COLOR_PAIR(1)); // Turn off the color pair

    // Print instructions
    mvwprintw(howWin, 1, 1, "How to Play:");
    mvwprintw(howWin, 3, 1, "1. Use the arrow keys to navigate");
    mvwprintw(howWin, 4, 1, "2. Use spacebar to jump");
    mvwprintw(howWin, 5, 1, "3. Collect all keys to win");
    mvwprintw(howWin, 6, 1, "4. Beware! The map will rotate every few seconds and rotate faster over time");
    mvwprintw(howWin, 8, 1, "Press any key to return to menu");

    wrefresh(howWin);

    // Wait for a key press before closing the window
    wgetch(howWin);

    refresh();
}


void splashscreen() {
    // Getting terminal dimensions
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // Initialize color pairs for later use
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    // Create a new window for the splash screen
    WINDOW *splash = newwin(30, 80, (yMax - 30) / 2, (xMax - 80) / 2);
    refresh();
    keypad(splash, true); // Enable keyboard input for the window

    // Apply blue background to the window and draw the border
    wbkgd(splash, COLOR_PAIR(1));
    wattron(splash, COLOR_PAIR(1));
    box(splash, 0, 0);
    wattroff(splash, COLOR_PAIR(1));

    // Print the game title in red
    wattron(splash, COLOR_PAIR(3));
    mvwprintw(splash, 5, 15, "   ___  ____  _________ __________    ___  ___ ");
    mvwprintw(splash, 6, 15, "  / _ \\/ __ \\/_  __/ _ /_  __/ __/___/ _ \\/ _ \\");
    mvwprintw(splash, 7, 15, " / , _/ /_/ / / / / __ |/ / / _//___/\\_, / // /");
    mvwprintw(splash, 8, 15, "/_/|_|\\____/ /_/ /_/ |_/_/ /___/    /___/\\___/ ");
    wattroff(splash, COLOR_PAIR(3));

    // Choices for the main menu
    char *choices[] = {"Play", "How to Play", "Exit"};
    int choice;
    int highlight = 0;

    // Main loop for the splash screen interactions
    while(1) {
        // Display the menu choices and highlight the selected one
        for(int i = 0; i < 3; ++i) {
            if(i == highlight)
                wattron(splash, A_REVERSE);
            else
                wattron(splash, COLOR_PAIR(2));

            // Print the menu item in the center of the window
            mvwprintw(splash, 12 + i * 2, (80 - strlen(choices[i])) / 2, "%s", choices[i]);

            wattroff(splash, COLOR_PAIR(2));

            // Turn off highlight attribute
            wattroff(splash, A_REVERSE);

        }
        wrefresh(splash);

        // Fetch user input
        choice = wgetch(splash);

        // Navigate through the menu based on key input
        if (choice == KEY_UP) {
            // If the up arrow key is pressed
            if (highlight > 0)
                // Move the highlight up in the menu
                highlight -= 1;
            else
                // Wrap around to the bottom of the menu
                highlight = 2;
        } else if (choice == KEY_DOWN) {
            // If the down arrow key is pressed
            if (highlight < 2)
                // Move the highlight down in the menu
                highlight += 1;
            else
                // Wrap around to the top of the menu
                highlight = 0;

        } else if (choice == 10) { // 10 Represents new line character, meaning 'Enter'
            if (highlight == 0) {
                // If 'Play' is selected
                // Break the loop to start the game
                return;

            } else if (highlight == 1) {
                // If 'How to Play' is selected
                // Display the instructions screen
                how_to_play();
                // After returning, clear the screen and redraw the border
                clear();
                box(splash, 0, 0);
                wrefresh(splash);
            } else if (highlight == 2) {
                // If 'Exit' is selected
                // Exit the program
                endwin();
                exit(0);
            }
        }
    }
    refresh();
}

void display_level(int i) {
	clear();
	// Calculting Max screen dimensions
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	if (i == 1) {
	// Callind level 1, if i is 1
		level1(yMax, xMax);
	} else if (i == 2) {
	// Calling level 2, if i is 2
		level2(yMax, xMax);
	} else if (i == 3) {
	// Calling level 3, if is 3
		level3(yMax, xMax);
	}
}

void endscreen() {
	clear();
	// Calculating max screen dimensions
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	// Creating endscreen window and box
	WINDOW *endscreen = newwin(30, 80, yMax/2 - 15, xMax/2 - 40);
        refresh();
        box(endscreen, 0, 0);
        wrefresh(endscreen);
	// print to endscreen
        mvwprintw(endscreen, 15, 24, "You Win! Click any key to exit.");
	wrefresh(endscreen);
	getch();
	endwin();
	exit(0);
}

void level1(int yMax, int xMax) {
    // Initialize color pairs
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);

    // Create level 1 window
    WINDOW *level1 = newwin(30, 80, yMax/2 - 15, xMax/2 - 40);

    wbkgd(level1, COLOR_PAIR(2));
    refresh();
	

    // Create level platform
    wattron(level1, COLOR_PAIR(1));
    mvwprintw(level1, 19, 0, "--------------------------------------------------------------------------------");
    wattroff(level1, COLOR_PAIR(1));

    // Create keys and display level name and level door
    wattron(level1, COLOR_PAIR(3));
    mvwprintw(level1, 5, 29, "Level 1: Grassy Plains");
    mvwprintw(level1, 18, 35, "O-X");
    mvwprintw(level1, 15, 76, " __ ");
    mvwprintw(level1, 16, 76, "|  |");
    mvwprintw(level1, 17, 76, "|  |");
    mvwprintw(level1, 18, 76, "|  |");
    wattroff(level1, COLOR_PAIR(3));
   
    wrefresh(level1); 
    // Getting user input
    user_input(yMax, xMax, 1);
}

void level2(int yMax, int xMax) {

    // Initialize color pairs
    init_pair(4, COLOR_RED, COLOR_RED);
    init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(6, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_RED);
    // Create a new window for level 2
    WINDOW *level2 = newwin(30, 80, (yMax - 30) / 2, (xMax - 80) / 2);

    wbkgd(level2, COLOR_PAIR(4));
    refresh();

    // Create level platforms
    wattron(level2, COLOR_PAIR(5));
    mvwprintw(level2, 19, 0, "-------------------------------------");
    mvwprintw(level2, 13, 31, "-------------------------------------------------");
    wattroff(level2, COLOR_PAIR(5));
    wattron(level2, COLOR_PAIR(2));
    mvwprintw(level2, 18, 31, "|---|");
    mvwprintw(level2, 17, 31, "|---|");
    mvwprintw(level2, 16, 31, "|---|");
    mvwprintw(level2, 15, 31, "|---|");
    mvwprintw(level2, 14, 31, "|---|");
    wattroff(level2, COLOR_PAIR(2));

    wattron(level2, COLOR_PAIR(4));

    // Loop to draw lava at the bottom of the screen
    for (int i = 1; i < 79; ++i) {
        mvwprintw(level2, 27, i, "8");
        mvwprintw(level2, 28, i, "8");
    }

    wattroff(level2, COLOR_PAIR(4));

    wattron(level2, COLOR_PAIR(6));
    // Printing keys
    mvwprintw(level2, 18, 15, "O-X");
    mvwprintw(level2, 12, 48, "O-X");
    mvwprintw(level2, 5, 30, "Level 2: Lava World");
    // Printing Door
    mvwprintw(level2, 9, 76, " __ ");
    mvwprintw(level2, 10, 76, "|  |");
    mvwprintw(level2, 11, 76, "|  |");
    mvwprintw(level2, 12, 76, "|  |");
    wattroff(level2, COLOR_PAIR(6));

    // Refresh and display level 2
    wrefresh(level2);
    // Get user input
    user_input(yMax, xMax, 2);
}

void level3(int yMax, int xMax) {
    // Initialize color pairs
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_WHITE);
    // Creating window
    WINDOW *level3 = newwin(30, 80, yMax/2 - 15, xMax/2 - 40);

    wbkgd(level3, COLOR_PAIR(1));
    refresh();

    wattron(level3, COLOR_PAIR(2));
    mvwprintw(level3, 5, 29, "Level 3: Dark Dungeons");
    wattroff(level3, COLOR_PAIR(2));
	
    // Creating level platforms
    wattron(level3, COLOR_PAIR(3));	    
    mvwprintw(level3, 13, 0, "----------------------");
    mvwprintw(level3, 18, 21, "------------------------------");
    mvwprintw(level3, 13, 51, "-----------------------------");
    wattroff(level3, COLOR_PAIR(3));
    wattron(level3, COLOR_PAIR(2));
    mvwprintw(level3, 13, 21, "|---|");
    mvwprintw(level3, 14, 21, "|---|");
    mvwprintw(level3, 15, 21, "|---|");
    mvwprintw(level3, 16, 21, "|---|");
    mvwprintw(level3, 17, 21, "|---|");
    
    mvwprintw(level3, 17, 45, "|---|");
    mvwprintw(level3, 16, 45, "|---|");
    mvwprintw(level3, 15, 45, "|---|");
    mvwprintw(level3, 14, 45, "|---|");
    mvwprintw(level3, 13, 45, "|---|");

    wattroff(level3, COLOR_PAIR(2));
    wattron(level3, COLOR_PAIR(2));
    // Printing Keys
    mvwprintw(level3, 12, 8, "o-X");
    mvwprintw(level3, 17, 37, "o-X");
    mvwprintw(level3, 12, 65, "o-X");
    // Level Door
    mvwprintw(level3, 9, 76, " __ ");
    mvwprintw(level3, 10, 76, "|  |");
    mvwprintw(level3, 11, 76, "|  |");
    mvwprintw(level3, 12, 76, "|  |");
    wattroff(level3, COLOR_PAIR(2));

    // Refresh and display level 3
    wrefresh(level3);
    // Get user input
    user_input(yMax, xMax, 3);
}

void quit_prompt(int level) {
	// Getting terminal dimensions
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	// Sets the colour scheme depending on level
        if (level == 1) {
                init_pair(1, COLOR_WHITE, COLOR_BLUE);
        } else if (level == 2) {
                init_pair(1, COLOR_WHITE, COLOR_RED);
        } else if (level == 3) {
                init_pair(1, COLOR_WHITE, COLOR_BLACK);
        }

	// Creating small quit prompt window
	WINDOW *quitWindow = newwin(3, 50, yMax / 2 - 14, (xMax - 50) / 2);
	box(quitWindow, 0, 0);
	
	// Setting background
	wbkgd(quitWindow, COLOR_PAIR(1));
	// Display the quit prompt in the new window
	mvwprintw(quitWindow, 1, 2, "Do you really want to quit? (y/n): ");
    wrefresh(quitWindow); // Refresh only the prompt window
	// Getting user input
	int confirm;

	// Looping until 'y' or 'n' are pressed
	do {
		confirm=wgetch(quitWindow);
	} while (confirm != 'y' && confirm != 'n');

	// Quitting if user types y
	if (confirm == 'y') {
		endwin();
		exit(0);
	// Resuming game if user types n
	} else if (confirm == 'n') {
		// Clear and refresh quitWindow
		wclear(quitWindow);
		wrefresh(quitWindow);
	}

}

void user_input(int yMax, int xMax, int level) {
    int numKeys = 0, reqKeys;
    int yCoord = (yMax/2-15); int xCoord = (xMax/2-40);
    int keyY; int keyX; int keyY1; int keyX1; int keyY2; int keyX2;
    bool gotKey1 = false; bool gotKey2 = false; bool gotKey3 = false;
    int ch;
    int playerYCoord; int playerXCoord;
    int doorxCoord = 76;
    char *player = malloc(sizeof(char));
    keypad(stdscr, true);

    // Sets the colour scheme depending on level
    if (level == 1) {
	keyY = 18, keyX = 35;
	playerYCoord = 18, playerXCoord = 1;
        reqKeys = 1;
        init_pair(1, COLOR_WHITE, COLOR_BLUE);
    } else if (level == 2) {
        reqKeys = 2;
	keyY = 18, keyX = 15, keyY1 = 12, keyX1 = 48;
	playerYCoord = 18, playerXCoord = 1;
        init_pair(1, COLOR_WHITE, COLOR_RED);
    } else if (level == 3) {
        reqKeys = 3;
	keyY = 12, keyX = 8, keyY1 = 17, keyX1 = 37, keyY2 = 12, keyX2 = 65;
	playerYCoord = 12, playerXCoord = 1;
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
    }
    
    attron(COLOR_PAIR(1));
    *player = '&';
    mvaddch(playerYCoord + yCoord, playerXCoord + xCoord, *player);

    mvprintw(0, 0, "Keys Collected: 0");
    do {
	// Get character
        ch = getch();

        mvprintw(1, 0, "Player Position: x=%d, y=%d", playerXCoord, playerYCoord);
	// Open quit prompt
        if (ch == 'q') {
            quit_prompt(level);
	// Open pause prompt
        } else if (ch == 'p') {
            pause_prompt(level);
	
        // Move Right
        } else if (ch == KEY_RIGHT || ch == 'd') { 
            if (at_boundry(level, playerYCoord, playerXCoord + 1) == 0) {
                mvaddch(playerYCoord + yCoord, playerXCoord + xCoord, ' ');
                playerXCoord++;
                mvaddch(playerYCoord + yCoord, playerXCoord + xCoord, *player);
		        refresh();
            }

        // Move Left
        } else if (ch == KEY_LEFT || ch == 'a') { 
            if (at_boundry(level, playerYCoord, playerXCoord - 1) == 0) {
                mvaddch(playerYCoord + yCoord, playerXCoord + xCoord, ' ');
                playerXCoord--;
                mvaddch(playerYCoord + yCoord, playerXCoord + xCoord, *player);
                refresh();
            }
        }
	
	// Key check for each level
	// Check keys for level 1
	if (level == 1) {
		// Checks if player is at key coordinate
		if (playerYCoord == keyY && playerXCoord == keyX && gotKey1 == false) {
			// Adds 1 to numKeys
			// gotKey1 = true;
			numKeys++;
			mvprintw(keyY+yCoord, keyX+xCoord+1, " ");
			mvprintw(keyY+yCoord, keyX+xCoord+2, " ");
			mvprintw(0,0, "Keys Collected: %d", numKeys);
		}
	// Check keys for level 2	
	} else if (level == 2) {
		// Checks if player is at key coordinates
                if (playerYCoord == keyY && playerXCoord == keyX && gotKey1 == false) {
                        // Adds 1 to numKeys
			// gotKey1 = true;
                        numKeys++;
                        mvprintw(keyY+yCoord, keyX+xCoord+1, " ");
                        mvprintw(keyY+yCoord, keyX+xCoord+2, " ");
                        mvprintw(0,0, "Keys Collected: %d", numKeys);
                } else if (playerYCoord == keyY1 && playerXCoord == keyX1 && gotKey2 == false) {
			// Adds 1 to numKeys
                        // gotKey2 = true;
                        numKeys++;
                        mvprintw(keyY+yCoord, keyX+xCoord+1, " ");
                        mvprintw(keyY+yCoord, keyX+xCoord+2, " ");
                        mvprintw(0,0, "Keys Collected: %d", numKeys);
		}
	// Check keys for level 3	
	} else if (level == 3) {
		// Checks if player is at key coordinates
                if (playerYCoord == keyY && playerXCoord == keyX && gotKey1 == false) {
                        // Adds 1 to numKeys
                        // gotKey1 = true;
			numKeys++;
                        mvprintw(keyY+yCoord, keyX+xCoord+1, " ");
                        mvprintw(keyY+yCoord, keyX+xCoord+2, " ");
                        mvprintw(0,0, "Keys Collected: %d", numKeys);
                } else if (playerYCoord == keyY1 && playerXCoord == keyX1 && gotKey2 == false) {
			// Adds 1 to numKeys
                        // gotKey2 = true;
                        numKeys++;
                        mvprintw(keyY+yCoord, keyX+xCoord+1, " ");
                        mvprintw(keyY+yCoord, keyX+xCoord+2, " ");
                        mvprintw(0,0, "Keys Collected: %d", numKeys);
		} else if (playerYCoord == keyY2 && playerXCoord == keyX2 && gotKey3 == false) {
			// Adds 1 to numKeys
                        // gotKey3 = true;
                        numKeys++;
                        mvprintw(keyY+yCoord, keyX+xCoord+1, " ");
                        mvprintw(keyY+yCoord, keyX+xCoord+2, " ");
                        mvprintw(0,0, "Keys Collected: %d", numKeys);
		}
	}
	// Refresh
	refresh();

	// Must be at door and have required number of keys
	} while ( numKeys < reqKeys|| (playerXCoord < doorxCoord)); 
	attroff(COLOR_PAIR(1));
}

int at_boundry(int level, int yCoord, int xCoord) {
	// Boundry checking for level 1
	if (level == 1) {
		if (yCoord == 0 || yCoord == 30 || xCoord == 0 || xCoord == 80) {

                    return 1;
        	} 
	// Boundry checking for level 2
	} else if (level == 2) {
		if (yCoord == 0 || yCoord == 30 || xCoord == 0 || xCoord == 80 || (xCoord == 31 && yCoord == 18)) {
                	return 1;
        	}
	// Boundry checking for level 3
	} else if (level == 3) {
		if (yCoord == 0 || yCoord == 30 || xCoord == 0 || xCoord == 80 || (xCoord == 21 && yCoord == 12) || (xCoord == 24 && yCoord == 17) || (xCoord == 45 && yCoord == 17)) {
                	return 1;
        	}	
	}
	// Return 0 if no boundry conflicts
	return 0;
}

void pause_prompt(int level) {
	// Getting terminal dimensions
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	// Sets the colour scheme depending on level
        if (level == 1) {
                init_pair(1, COLOR_WHITE, COLOR_BLUE);
        } else if (level == 2) {
                init_pair(1, COLOR_WHITE, COLOR_RED);
        } else if (level == 3) {
                init_pair(1, COLOR_WHITE, COLOR_BLACK);
        }

        // Creating small pause window
	WINDOW *pauseWindow = newwin(3, 50, yMax / 2 - 14, (xMax - 50) / 2);

	box(pauseWindow, 0, 0);
	wbkgd(pauseWindow, COLOR_PAIR(1));
        // Display the pause prompt in the new window
	mvwprintw(pauseWindow, 1, 2, "Click 'p' to unpause the game.");
	wrefresh(pauseWindow); // Refresh only the prompt window
	
	// Getting user input
        int unpause;

	// Unpausing only if user types 'p'
	do {
		unpause=wgetch(pauseWindow);
	} while (unpause != 'p');
	
	// Clear and refresh pauseWindow
	wclear(pauseWindow);
	wrefresh(pauseWindow);
}
