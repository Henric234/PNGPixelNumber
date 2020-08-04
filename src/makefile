DEPPATH = ../dependencies/lodepng/

all: output

output: main.o main.o lodepng.o
	g++ main.o lodepng.o -o output

main.o: main.cpp
	g++ -c -std=c++17 -lstdc++fs main.cpp

lodepng.o:
	g++ -c $(DEPPATH)lodepng.cpp -Wall -Wextra -pedantic -ansi -O3 -std=c++17 -o lodepng.o

clean:
	rm *.o
