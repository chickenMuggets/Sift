#include <iostream>
#include "getselectedcharacter.h"

std::string interpretKeys(int ch) {
    switch (ch) {
        #ifdef _WIN32
        case 113:  // 'q' to quit
            return "q";
            break;
        case -32:  // Arrow keys detection (ANSI escape code)
            ch = getchrim();
            if (ch == 72) {  // Up arrow key
                return "up";
            } else if (ch == 80) {  // Down arrow key
                return "down";
            }
            break;
        case 58: // ':'
            return ":";
            break;
        default:
            return "none";
            break;
        #else
        #endif
    }
    return "none";
}