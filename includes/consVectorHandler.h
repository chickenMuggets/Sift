#ifndef __CONSVECTORHANDLER_H__
#define __CONSVECTORHANDLER_H__

#include <vector>
#include <iostream>

namespace consolevectorhandler {
    void updateVector(std::string newString, double updateNum);
    void addToVector(std::string newString);
    void updateScreen();
    int getCurrentSelected();
    void changeSelection(int newSelectionItem);
    void clearConsoleVector();
}
#endif // __CONSVECTORHANDLER_H__