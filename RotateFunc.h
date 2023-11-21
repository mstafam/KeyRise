/*
 * Names: Mustafa Mohamed, Sami Elsayed
 * Lab: 9-11
 */

// Function Prototypes

/*
 * purpose: Display the splash screen with game title and menu options
 * params:  None
 * return:  Void
 */
void splashscreen();

/*
 * purpose: Display a specific game level based on the level number provided
 * params:  int i - The level number to display (1, 2, or 3).
 * return:  Void
 */
void display_level(int i);

/*
 * purpose: Display the end screen when the game is completed
 * params:  None
 * return:  Void
 */
void endscreen();

/*
 * purpose: Display the first level of the game
 * params:  int yMax - The maximum Y dimension of the screen
 *          int xMax - The maximum X dimension of the screen
 * return:  Void
 */
void level1(int yMax, int xMax);

/*
 * purpose: Display the second level of the game
 * params:  int yMax - The maximum Y dimension of the screen
 *          int xMax - The maximum X dimension of the screen
 * return:  Void
 */
void level2(int yMax, int xMax);

/*
 * purpose: Display the third level of the game
 * params:  int yMax - The maximum Y dimension of the screen
 *          int xMax - The maximum X dimension of the screen
 * return:  Void
 */
void level3(int yMax, int xMax);

