CXX  	 = clang++
LIBS 	 = `sdl2-config --libs --cflags` `pkg-config sfml-all --libs --cflags` -lSDL2_image -lGLEW -lGL
CFLAGS = -Wall -g -std=c++11
SRCS 	 = $(wildcard *.cpp)
OBJS 	 = $(patsubst %.cpp, %.o, $(SRCS))

all: build run

build: $(OBJS)
	$(CXX) $(OBJS) -o main.out  $(LIBS)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

run:
	./main.out

clean:
	rm -f *.o main.out
