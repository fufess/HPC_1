cpi_cuda	: cpi_cuda.cu gettime.c
	        nvcc --gpu-architecture=sm_60 -o cpi_cuda cpi_cuda.cu gettime.c
cpi_test	: cpi_test.cu gettime.c
		nvcc --gpu-architecture=sm_60 -o cpi_test cpi_test.cu gettime.c
all             : cpi_cuda cpi_test
clean:
	        rm -f cpi_cuda cpi_test
