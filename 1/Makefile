CC=g++
CFLAGS=-Wall -g
LIBS=-lGL -lGLEW -lGLU -lglut -lm

all: build run
	
build:
	$(CC) -c *.cpp $(CFLAGS)
	$(CC) *.o -o program.out $(LIBS)

run:
	./program.out

clean:
	rm *.o program.out
