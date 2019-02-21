#include "term.hpp"

namespace Term {

	Win *active_win;

	vector<Win*> Wins;
		
	// using namespace Term;
	
	
	
	void move_cursor(int x,int y) {
	 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{.X = (SHORT)x, .Y = (SHORT)y});
	}
	
	bool press(Term::Win* w,unsigned int key_code) {
	 	if(active_win == w && w != NULL)
	 		return ( GetAsyncKeyState(key_code) & 0x8000 );
	 	else
		 	return ( GetAsyncKeyState(key_code) & 0x8000 ); 
	}
	
	void render() {
		// Use Wins
		for(auto it : Wins) {
			renderWindow(it);
		}
	}

	void renderWindow(Win* win) {
		if(win == nullptr) { return; }
		Win w = *win;
	}
	
	void render(int count,...) {
		va_list args;
		va_start(args,count);
		vector<Term::Win*> list;
		
		for (int i=0;i<count;i++) {
			Win* w = va_arg(args,Term::Win*);
			list.push_back(w);
		}
		va_end(args);
		for(auto it : list) {
			renderWindow(it);
		}
	}
}