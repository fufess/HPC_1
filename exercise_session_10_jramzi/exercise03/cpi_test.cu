// Using CUDA device to calculate pi
#include <stdio.h>
#include <cuda.h>
extern "C" double getTime(void);

#define NBIN 1000000000  // Number of bins
//#define num_block  (2*56)  // Number of thread blocks
//#define num_thread  (2*8)  // Number of threads per block

// Kernel that executes on the CUDA device
__global__ void cal_pi(double *sum, int nbin, double step, int nthreads, int nblocks) {
	int i;
	double x;
	int idx = blockIdx.x*blockDim.x+threadIdx.x;  // Sequential thread index across the blocks
	for (i=idx; i< nbin; i+=nthreads*nblocks) {
		x = (i+0.5)*step;
		sum[idx] += 4.0/(1.0+x*x);
	}
}

// Main routine that executes on the host
int main(int argc, char **argv) {

	int c;
	int num_block;
	int num_thread;
	//printf("initial argc = %d\n", argc);
	while(argc--){
		c = argc;

		//printf("c = %d\n", argc);
		printf("%d\n", atoi(*argv++));
		if (c == 2) num_block = atoi(*argv); 
		if (c == 1) num_thread = atoi(*argv);
	}

	dim3 dimGrid(num_block,1,1);  // Grid dimensions
	dim3 dimBlock(num_thread,1,1);  // Block dimensions
	double *sumHost, *sumDev;  // Pointer to host & device arrays
	double pi = 0;
	int tid;

	double step = 1.0/NBIN;  // Step size
	size_t size = num_block*num_thread*sizeof(double);  //Array memory size
	sumHost = (double *)malloc(size);  //  Allocate array on host
	cudaMalloc((void **) &sumDev, size);  // Allocate array on device
   	double start = getTime();

	//printf("INITIAL PRINT 1= %s and 2 = %s\n", argv,argv-1 );

	// Initialize array in device to 0
	cudaMemset(sumDev, 0, size);
	// Do calculation on device
	cal_pi <<<dimGrid, dimBlock>>> (sumDev, NBIN, step, num_thread, num_block); // call CUDA kernel
	// Retrieve result from device and store it in host array
	cudaMemcpy(sumHost, sumDev, size, cudaMemcpyDeviceToHost);
	for(tid=0; tid<num_thread*num_block; tid++)
		pi += sumHost[tid];
	pi *= step;

	// Print results
	double delta = getTime() - start;
	printf("PI = %.16g computed in %.4g seconds with NUM_BLOCK = %d and NUM_THREAD = %d\n", pi, delta, num_block, num_thread);
	// Cleanup
	free(sumHost);
	cudaFree(sumDev);

	return 0;
}

