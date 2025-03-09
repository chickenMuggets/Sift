#ifdef _WIN32
#include <conio.h>
#else
#include <iostream>
#include <termios.h>
#include <unistd.h>
#endif


#ifdef _WIN32
int getchrim() {
    return _getch();
}
#else
int getchrim() {
    struct termios oldt, newt;
    char ch;
    
    tcgetattr(STDIN_FILENO, &oldt);  // Get the current terminal settings
    newt = oldt;  // Copy the settings
    newt.c_lflag &= ~(ICANON | ECHO);  // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Apply the new settings
    
    ch = getchar();  // Read a character
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restore the old settings
    
    return ch;
}
#endif
