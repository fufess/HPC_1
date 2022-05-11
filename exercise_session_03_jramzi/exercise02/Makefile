sum		: sum.o getTime.o
	cc -O3 -o sum sum.o getTime.o
sum.o           : sum.c getTime.h
	cc -O3 -c -o sum.o sum.c
getTime.o       : getTime.c getTime.h
	cc -O3	-c -o getTime.o getTime.c
clean:
	rm -f sum sum.o getTime.o
