cpi_openacc	: cpi_openacc.c gettime.c
	cc -ta=tesla,cc60 -o cpi_openacc cpi_openacc.c gettime.c
all		: cpi_openacc
clean:
	rm -f cpi_openacc
