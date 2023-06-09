#include "color.h"

// Function to set the color of the console text output
void set_color(int color) {
    // Get a handle to the standard output device (console)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set the console text attribute (color) using the handle and the provided color value
    SetConsoleTextAttribute(hConsole, color);
}
