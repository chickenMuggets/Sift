#include <iostream>
#include "includes/getterminalsize.h"

int main() {
    while (true)
    {
        std::cout << "rows: " << getTerminalSize(0) << " Columns: " << getTerminalSize(1) << "\n";
    }
    
    return 0;
}