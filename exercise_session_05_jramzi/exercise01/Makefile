linear_combination	: linear_combination.o
	cc -o linear_combination linear_combination.o
linear_combination.o	: linear_combination.c
	cc -O3 -c -o linear_combination.o linear_combination.c
all			: linear_combination linear_combination.o

clean			:
	rm -f linear_combination linear_combination.o
