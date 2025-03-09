#ifndef __CONSVECTORHANDLER_H__
#define __CONSVECTORHANDLER_H__

#include <vector>
#include <iostream>

namespace consolevectorhandler {
    void updateVector(std::string newString, double updateNum);
    void addToVector(std::string newString);
    void updateScreen();
    int getCurrentSelected();
    std::string getSelectedFile();
    void changeSelection(int newSelectionItem, int maxSelection);
    void clearConsoleVector();
    int getVectorLength();
}
#endif // __CONSVECTORHANDLER_H__