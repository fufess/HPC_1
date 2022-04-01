parallel		: parallel.o
	cc -o parallel parallel.o
parallel.o		: parallel.c
	cc -O3 -c -o parallel.o parallel.c
all			: parallel parallel.o

clean			:
	rm -f parallel parallel.o
