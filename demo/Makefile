all: build

run: build
	./test

build: main.cpp
	g++ -lGL -lGLU -lglut main.cpp -o test

clean:
	rm test

.PHONY: run build clean
