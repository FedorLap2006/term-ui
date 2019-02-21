CX = g++ -std=c++14 -W
CC = gcc -std=c11 -s -W

all: src
	ar rc libTermUI.a *.o 
	rm *.o
	rm -f *.obj

src:
	$(CX) -lgdi32  -c *.cpp 

#	$(CC) -W -c *.c

