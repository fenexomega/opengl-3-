CXX  	 = clang++
PROGRAM  = main.out
LIBS 	 = `sdl2-config --libs --cflags` \
		   `pkg-config sfml-all --libs --cflags` \
		   -lSDL2_image -lGLEW -lGL
DIRS     = $(wildcard */)
INCDIRS  = $(foreach d, $(DIRS),-I$d)
CFLAGS   = -Wall -g -std=c++11
SRCS 	 = $(wildcard *.cpp) $(wildcard */*.cpp)
OBJS 	 = $(patsubst %.cpp, %.o, $(SRCS))

all: build
	@echo $(SRCDIRS)

build: $(OBJS)
	$(CXX) $(OBJS) -o $(PROGRAM)  $(LIBS)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CFLAGS) $(INCDIRS)

run:
	./$(PROGRAM)

clean:
	rm -f $(OBJS) $(PROGRAM)
