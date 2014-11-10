CXX=g++
LIBS=-lSDL2 -lGLEW -lGL
CFLAGS=-Wall -g -std=c++11

all: build run

build:
	$(CXX) *.cpp -o main.out $(CFLAGS) $(LIBS)

run:
	./main.out

clean: 
	rm -f *.o main.out
