#include <mpi.h>
#include <stdio.h>
#include <math.h>

double partial_inv_factorial(int n_new, int n_old){
    // Force factorial(0)=factorial(1)=1
    if (n_new<=1) return 1;

    double ret = 1.0;
    for (int k=n_old+1; k<=n_new; k++)
        if (k>0) ret /= k;
    return ret;
}

int main(int argc, char** argv) {
    int N = 1000000000;
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes and rank of the process
    int size, my_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    double local_sum=0.;
    double val=1.;

    for(int i=1; i<N; i++){
        val = pow(-1, i)/(2 * i + 1);
        local_sum += val;
    }

    double global_sum=0;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (my_rank==0){
        printf("pi=%.20g\n", global_sum);
    }
    // Finalize the MPI environment.
    MPI_Finalize();
}
