cpi 		: cpi.o getTime.o
	cc -o cpi cpi.o getTime.o
cpi.o	 	: cpi.c getTime.h
	cc -O3 -ffast-math -mavx2 -c -o cpi.o cpi.c
getTime.o 	: getTime.c getTime.h
	cc -O3 -ffast-math -mavx2 -c -o getTime.o getTime.c
cpi_mpi.o	: cpi_mpi.c getTime.h
	cc -O3 -ffast-math -mavx2 -c -o cpi_mpi.o cpi_mpi.c
cpi_mpi       	: cpi_mpi.o getTime.o
	cc -o cpi_mpi cpi_mpi.o getTime.o
all		: cpi cpi.o getTime.o cpi_mpi.o cpi_mpi

clean:
	rm -f cpi cpi.o getTime.o cpi_mpi.o cpi_mpi
