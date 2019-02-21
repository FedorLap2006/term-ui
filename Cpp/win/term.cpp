#include "term.hpp"	

namespace Term {
	
	void move_cursor(int x,int y) {
	 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{.X = (SHORT)x, .Y = (SHORT)y});
	}


	class Widget {
	protected:
		int bx,by; // begin x,y
		int ex,ey; // end x,y
		string buf;
		vector<Widget*> child;
	public:

		// childs
		virtual void addChild(Widget* c) {
			child.push_back(c);
		}
		virtual void removeChild(size_t index) {
			if( index >= child.size() )
				return;
			child.erase(child.begin()+index);
		}

		// draw and display
		virtual void setContext(string buffer) {
			this->buf = buffer;
		}
		virtual void setContext(char* str) {
			this->buf = str;
		}
		virtual void setContext(stringstream ss) {
			this->buf = ss.str();
		}
		virtual void render() {
			move_cursor(this->bx,this->by);
			// do stuff...
		}
		

		void resize(size_t sx,size_t sy) {
			this->ex=sx;
			this->ey = sy;
		}
		void move(size_t mx,size_t my) {
			this->ex = this->bx + mx;
			this->ey = this->by + my;
			this->bx = mx;
			this->by = my;
		}

		// DANGER !!!
		void resetBuffer() { // WARN: clear all buffer of the widget
			this->buf = "";
		}
	};

	class Window : public Widget {
	public:
		void render() override {
			move_cursor(this->bx,this->by);
		}
	private:
//		int bx,by; // begin x,y
//		int ex,ey; // end x,y
	};

	Window *active_win;

	vector<Window*> wins;
		
	// using namespace Term;
	
	
	

	
//	bool press(Term::Win* w,unsigned int key_code) {
//	 	if(active_win == w && w != NULL)
//	 		return ( GetAsyncKeyState(key_code) & 0x8000 );
//	 	else
//		 	return ( GetAsyncKeyState(key_code) & 0x8000 ); 
//	}
	void renderWindow(Window* win) {

	}
	void renderAll() {
		// Use wins
		for(auto it : wins) {
			renderWindow(it);
		}
	}
	
	void renderAll(int count,...) {
		va_list args;
		va_start(args,count);
		vector<Term::Window*> list;
		
		for (int i=0;i<count;i++) {
			Window* w = va_arg(args,Term::Window*);
			list.push_back(w);
		}
		va_end(args);
		for(auto it : list) {
			renderWindow(it);
		}
	}
}
