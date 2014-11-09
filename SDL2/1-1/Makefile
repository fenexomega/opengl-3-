CC=g++
LIBS= -lSDL2 -lGL -lGLEW 
CFLAGS= -g -Wall -std=c++11

all: build run

build:
	$(CC) *.cpp -o main.out $(LIBS) $(CFLAGS)
run:
	./main.out
clean:
	rm -f main.out 

