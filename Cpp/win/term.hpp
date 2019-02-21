#ifndef _TERM_HPP_
#define _TERM_HPP_

#include <stdio.h>
#include <iostream>
#include <windows.h>

#include <string>
#include <sstream>
#include <stdarg.h>
#include <vector>

// #include <stdbool.h>

using namespace std;

namespace Term {
	class Widget;
	class Window;

	extern void move_cursor(int x,int y);

	extern vector<Window*> wins;	
	
	extern void renderWindow(Window*);

	extern void renderAll(int count,...);
	extern void renderAll();
} /* namespace Term */

#endif
