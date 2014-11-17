CXX=g++
SFML=`pkg-config sfml-all --libs `
SDL2=`sdl2-config --libs --cflags`
LIBS= -lGLEW -lGL
CFLAGS=-Wall -std=c++11

all: build run

build:
	$(CXX) *.cpp -o main.out $(CFLAGS) $(LIBS) $(SFML) $(SDL2)
run:
	./main.out

clean: 
	rm -f *.o main.out
