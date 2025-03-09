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
        case 13:
            return "enter";
            break;
        default:
            return "none";
            break;
        #else
        case 'q':  // 'q' to quit
            return "q";
            break;
        case 27:  // Arrow keys detection (ANSI escape code)
            ch = getchrim();
            if (ch == 91) {  // '[' character
                ch = getchrim();
                if (ch == 65) {  // Up arrow key
                    return "up";
                } else if (ch == 66) {  // Down arrow key
                    return "down";
                }
            }
            break;
        case ':': // ':'
            return ":";
            break;
        default:
            return "none";
            break;
        #endif
    }
    return "none";
}