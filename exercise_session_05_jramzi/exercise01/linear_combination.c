#include <stdio.h>
#include <stdlib.h>

#define N 4 //int N = 4;
struct complex_vector {
        int real[N*sizeof(int)]; // = malloc(N*sizeof(int));
        int imgnry[N*sizeof(int)]; // = malloc(N * sizeof(int));
};

int linear_combination(struct complex_vector x, struct complex_vector y, int a, struct complex_vector z);

int main()
{
        struct complex_vector x;
        struct complex_vector y;
        struct complex_vector z;

        int a = 3;

        for (int i=0; i<=N; i++){
                x.real[i] = i + 1;
                y.real[i] = x.real[i] * 3 - 1;
        };

        for (int j=0; j<=N; j++){
                x.imgnry[j] = j + 2;
                y.imgnry[j] = x.imgnry[j] * 2 - 1;
        };

        for (int k=0; k<=N; k++){
            printf("x.real: %d, y.real: %d\n", x.real[k], y.real[k]);
        }

        for (int k=0; k<=N; k++){
            printf("x.imgnry: %d, y.imgnry: %d\n", x.imgnry[k], y.imgnry[k]);
        }

        linear_combination(x, y, a, z);
};

int linear_combination(struct complex_vector x, struct complex_vector y, int a, struct complex_vector z) {

        for (int i=0; i<=N; i++){
                z.real[i] = x.real[i] + a * y.real[i];
        };

	for (int i=0; i<=N; i++){
        	z.imgnry[i] = x.imgnry[i] + a * y.imgnry[i];
        };
        printf("\n");

        for (int k=0; k<=N; k++){
        	printf("z.real: %d, z.imgnry: %d\n", z.real[k], z.imgnry[k]);
        }
        return 0;
};
