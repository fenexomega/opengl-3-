CXX=g++
LIBS=-lSDL2 -lGLEW -lGL
CFLAGS=-Wall -g

all: build run

build:
	$(CXX) *.cpp -o main.out $(CFLAGS) $(LIBS)

run:
	./main.out

clean: 
	rm -f *.o main.out
