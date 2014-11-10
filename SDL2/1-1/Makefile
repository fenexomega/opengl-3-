CXX=g++
SFML=`pkg-config sfml-all --libs `
SDL2=`sdl2-config --libs --cflags`
LIBS= -lGLEW -lGL
CFLAGS=-Wall -g -std=c++11

all: build run

build:
ifeq ($(LIB),SFML)
	$(CXX) *.cpp -o main.out $(CFLAGS) $(LIBS) $(SFML)
else
	$(CXX) *.cpp -o main.out $(CFLAGS) $(LIBS) $(SDL2)	
endif
run:
	./main.out

clean: 
	rm -f *.o main.out
