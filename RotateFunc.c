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


void how_to_play() {

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
}


void splashscreen() {
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
}

void display_level(int i) {
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
	// Calculating max screen dimensions
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	// Creating endscreen window and box
	WINDOW *endscreen = newwin(30, 80, yMax/2 - 15, xMax/2 - 40);
        refresh();
        box(endscreen, 0, 0);
        wrefresh(endscreen);
        mvwprintw(endscreen, 15, 24, "You Win! Click any key to exit.");
	wrefresh(endscreen);
	getch();
	endwin();
	exit(0);
}

void level1(int yMax, int xMax) {
    // Initialize color pairs
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);

    // Create level 1 window
    WINDOW *level1 = newwin(30, 80, yMax/2 - 15, xMax/2 - 40);

    wbkgd(level1, COLOR_PAIR(2));
    refresh();
    wattron(level1, COLOR_PAIR(3));
    wrefresh(level1);

    // Print the key and level title
    mvwprintw(level1, 18, 40, "O-X");
    mvwprintw(level1, 5, 29, "Level 1: Grassy Plains");

    wattroff(level1, COLOR_PAIR(3));

    wattron(level1, COLOR_PAIR(1));

    // Loop to create a grassy ground pattern across the window
    int x = 0;
    while (x < 74) {
        mvwprintw(level1, 20, x, "|______|");
        x += 6;
    }

    wattroff(level1, COLOR_PAIR(1));

    wrefresh(level1);
}

void level2(int yMax, int xMax) {

    // Initialize color pairs 
    init_pair(4, COLOR_RED, COLOR_RED);   
    init_pair(5, COLOR_YELLOW, COLOR_YELLOW); 
    init_pair(6, COLOR_WHITE, COLOR_RED);

    // Create a new window for level 2
    WINDOW *level2 = newwin(30, 80, (yMax - 30) / 2, (xMax - 80) / 2);

    wbkgd(level2, COLOR_PAIR(4));
    refresh();

    // Variables to control the positioning of obstacles
    int x = 1;
    int y = 15;
    bool UP = true;
    
    // Enable the orange color pair for drawing obstacles
    wattron(level2, COLOR_PAIR(5));

    // Loop to create platforms
    while (x < 70) {
        mvwprintw(level2, y + 1, x, "|___||___||___||___|");

        if (UP) {
            y -= 5;
            UP = false;
        } else {
            y += 5;
            UP = true;
        }
        x += 26;
    }

    wattroff(level2, COLOR_PAIR(5));

    wattron(level2, COLOR_PAIR(4));

    // Loop to draw lava at the bottom of the screen
    for (int i = 1; i < 79; ++i) {
        mvwprintw(level2, 27, i, "8");
        mvwprintw(level2, 28, i, "8");
    }

    wattroff(level2, COLOR_PAIR(4));

    wattron(level2, COLOR_PAIR(6));
    mvwprintw(level2, 9, 36, "O-X");
    mvwprintw(level2, 14, 9, "O-X");
    mvwprintw(level2, 5, 30, "Level 2: Lava World");

    wattroff(level2, COLOR_PAIR(6));

    // Refresh and display level 2
    wrefresh(level2);
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

    // Variables to control the positioning of platforms
    int x = 1, y = 19;
    bool UP = true;

    wattron(level3, COLOR_PAIR(3));

    // Loop to create platforms
    while (x < 68 && y < 30) {
        mvwprintw(level3, y+1, x, "|____|");
        mvwprintw(level3, y+1, x+6, "|____|");

        if (UP) {
            y -= 3;
            UP = false;
        } else {
            y += 3;
            UP = true;
        }
        x += 12;
    }

    wattroff(level3, COLOR_PAIR(3));

    wattron(level3, COLOR_PAIR(2));
    // Printing Keys
    mvwprintw(level3, 18, 5, "o-X");
    mvwprintw(level3, 15, 42, "o-X");
    mvwprintw(level3, 15, 69, "o-X");

    wattroff(level3, COLOR_PAIR(2));

    // Refresh and display level 3
    wrefresh(level3);
}

