CFLAGS=-O3 -ffast-math -mavx2
CC=CC

all: init.o io.o jacobi.o main

init.o: init.cpp init.h
	cc -O3 -ffast-math -fopenmp -c -o init.o init.cpp
io.o: io.cpp io.h
	cc -O3 -ffast-math -fopenmp -c -o io.o io.cpp
jacobi.o: jacobi.cpp jacobi.h
	cc -O3 -ffast-math -fopenmp -c -o jacobi.o jacobi.cpp
main: init.o io.o jacobi.o
	cc -O3 -ffast-math -fopenmp -c -o main init.o io.o jacobi.o
clean: 
	rm -f main init.o io.o jacobi.o
