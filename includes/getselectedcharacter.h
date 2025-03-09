#ifndef __GETSELECTEDCHARACTER_H__
#define __GETSELECTEDCHARACTER_H__

#ifdef _WIN32
#include <conio.h>
#else
#include <iostream>
#include <termios.h>
#include <unistd.h>
#endif

char getchrim();
int kbhit();
#endif // __GETSELECTEDCHARACTER_H__