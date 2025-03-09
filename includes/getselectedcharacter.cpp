#ifdef _WIN32
#include <conio.h>
#else
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#endif


#ifdef _WIN32
int getchrim() {
    return _getch();
}
int kbhit() {
    return _kbhit();
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
int kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;

    if (!initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);  // Check if data is available on stdin
    return bytesWaiting;
}
#endif
