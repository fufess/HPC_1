cpi_cuda	: cpi_cuda.cu gettime.c
	        nvcc --gpu-architecture=sm_60 -o cpi_cuda cpi_cuda.cu gettime.c
all             : cpi_cuda
clean:
	        rm -f cpi_cuda
