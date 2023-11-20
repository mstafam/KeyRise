// libraries
# include <stdio.h>
# include <stdlib.h>
# include <ncurses.h>
# include "RotateFunc.h"
# include <string.h>


void how_to_play() {
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    init_pair(1, COLOR_BLUE, COLOR_BLACK);

    WINDOW *howWin = newwin(30, 80, (yMax - 30) / 2, (xMax - 80) / 2);
    wattron(howWin, COLOR_PAIR(1));
    box(howWin, 0, 0);
    wattroff(howWin, COLOR_PAIR(1));
    
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
    init_pair(3, COLOR_RED, COLOR_BLACK);

    WINDOW *splash = newwin(30, 80, (yMax - 30) / 2, (xMax - 80) / 2);
    refresh();
    keypad(splash, true); // Enable keyboard input for the window
    wbkgd(splash, COLOR_PAIR(1)); 
    wattron(splash, COLOR_PAIR(1));
    box(splash, 0, 0); 
    wattroff(splash, COLOR_PAIR(1)); // Turn off red color pair

    // Display the game title
    wattron(splash, COLOR_PAIR(3));
    mvwprintw(splash, 5, 15, "   ___  ____  _________ __________    ___  ___ ");
    mvwprintw(splash, 6, 15, "  / _ \\/ __ \\/_  __/ _ /_  __/ __/___/ _ \\/ _ \\");
    mvwprintw(splash, 7, 15, " / , _/ /_/ / / / / __ |/ / / _//___/\\_, / // /");
    mvwprintw(splash, 8, 15, "/_/|_|\\____/ /_/ /_/ |_/_/ /___/    /___/\\___/ ");
    wattroff(splash, COLOR_PAIR(3)); // Turn off red color pair


    char *choices[] = {"Play", "How to Play", "Exit"};
    int choice;
    int highlight = 0;

    while(1) {
        for(int i = 0; i < 3; ++i) {
            if(i == highlight)
                wattron(splash, A_REVERSE); // Highlight the selected item
            else
                wattron(splash, COLOR_PAIR(2)); // Apply white color to text
            
            mvwprintw(splash, 12 + i * 2, (80 - strlen(choices[i])) / 2, "%s", choices[i]);
            wattroff(splash, COLOR_PAIR(2)); // Turn off white color for other items
            wattroff(splash, A_REVERSE); // Turn off highlight
        }
        wrefresh(splash);

        choice = wgetch(splash); // Get user input

        switch(choice) {
            case KEY_UP:
                if (highlight > 0)
                    highlight -= 1;
                else
                    highlight = 2;
                break;
            case KEY_DOWN:
                if (highlight < 2)
                    highlight += 1;
                else
                    highlight = 0;
                break;
            case 10: // Enter key
		if (highlight == 0) {
			return;
		}
		else if (highlight == 1) { // If "How to Play" is selected
                    how_to_play(); // Call the function to display the instructions
                    // Redraw the splash screen after returning from the instructions
                    clear();
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
        mvwprintw(endscreen, 15, 24, "You Win! Click any key to exit.");
	wrefresh(endscreen);
	getch();
	endwin();
	exit(0);
}

void level1(int yMax, int xMax) {
	// Creating level1 window and box
	init_pair(1, COLOR_GREEN, COLOR_GREEN);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);
	WINDOW *level1 = newwin(30, 80, yMax/2 - 15, xMax/2 - 40);
	wbkgd(level1, COLOR_PAIR(2));
	refresh();
	wattron(level1, COLOR_PAIR(3));
	wrefresh(level1);
	mvwprintw(level1, 18, 40, "o-X");
	mvwprintw(level1, 5, 29, "Level 1: Grassy Plains");
	wattroff(level1, COLOR_PAIR(3));
	wattron(level1, COLOR_PAIR(1));
	int x = 0;
	while (x < 74) {
		//mvwprintw(level1, 19, x+1, "______");
        	mvwprintw(level1, 20, x, "|______|");
		x += 6;
	}
	wattroff(level1, COLOR_PAIR(1));
	wrefresh(level1);
}


void level2(int yMax, int xMax) {
    init_pair(4, COLOR_RED, COLOR_RED);   
    init_pair(5, COLOR_YELLOW, COLOR_YELLOW); 
    init_pair(6, COLOR_WHITE, COLOR_RED);

    WINDOW *level2 = newwin(30, 80, (yMax - 30) / 2, (xMax - 80) / 2);
    wbkgd(level2, COLOR_PAIR(4));
    refresh(); 

    int x = 1;
    int y = 15;
    bool UP = true;
    
    wattron(level2, COLOR_PAIR(5));
    while (x < 70) { 
        //mvwprintw(level2, y, x, " ___  ___  ___  ___ ");
        mvwprintw(level2, y + 1, x, "|___||___||___||___|");

        if (UP == true){
            y-=5;
            UP = false;
        } else{
            y+=5;
            UP = true;
        }
        x += 26;
    }

    //mvwprintw(level2, 15, 73, " ___ ");
    mvwprintw(level2, 16, 72, "|___|");
    wattroff(level2, COLOR_PAIR(5)); 

    // Draw lava
    wattron(level2, COLOR_PAIR(4)); 
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
    wrefresh(level2);

}

void level3(int yMax, int xMax) {
	// Creating level3 window and box
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_WHITE);
	WINDOW *level3 = newwin(30, 80, yMax/2 - 15, xMax/2 - 40);
	wbkgd(level3, COLOR_PAIR(1));
	refresh();
	wattron(level3, COLOR_PAIR(2));
	mvwprintw(level3, 5, 29, "Level 3: Dark Dungeons");
	wattron(level3, COLOR_PAIR(2));
	int x = 1, y = 19;
	bool UP = true;
	wattron(level3, COLOR_PAIR(3));
	while (x < 68 && y < 30) {
                mvwprintw(level3, y+1, x, "|____|");
                mvwprintw(level3, y+1, x+6, "|____|");

		if (UP == true) {
			y -= 3;
			UP = false;
		} else {
			y += 3;
			UP = true;
		}
                x += 12;
	}

	mvwprintw(level3, y-2, x, "|____|");
	wattroff(level3, COLOR_PAIR(3));
	wattron(level3, COLOR_PAIR(2));
	mvwprintw(level3, 18, 5, "o-X");
	mvwprintw(level3, 15, 42, "o-X");
	mvwprintw(level3, 15, 69, "o-X");
	wattroff(level3, COLOR_PAIR(2));
	wrefresh(level3);
}
