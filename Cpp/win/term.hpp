#ifndef _TERM_HPP_
#define _TERM_HPP_

#include <stdio.h>
#include <iostream>
#include <windows.h>

#include <stdarg.h>
#include <vector>

// #include <stdbool.h>

using namespace std;

namespace Term {

	typedef struct {
		int x,y;
		int xs,ys;
		// ...
	}Win;

	// extern
	
	extern void renderWindow(Win* win);
	
	extern void move_cursor(int x,int y);

	extern bool press(Win* w,unsigned int key_code);

	extern vector<Win*> Wins;	
	
	extern void render(int count,...);
	extern void render();
} /* namespace Term */

#endif