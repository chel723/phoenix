.PHONY: all

all:
	g++ -std=c++1y -o main.o -c main.cpp -Wall -O `pkg-config --cflags --libs opencv` -I.
	g++ -o main main.o `pkg-config --cflags --libs opencv` -L.

clean:
	rm -f *.o main
