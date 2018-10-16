all: test

test: main.o sum.o
	g++ main.o sum.o -o test

main.o: main.cpp
	g++ -c main.cpp

sum.o: sum.cpp
	g++ -c sum.cpp

clean:
	rm -rf *.o test
