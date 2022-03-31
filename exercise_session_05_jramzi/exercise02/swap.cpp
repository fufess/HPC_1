#include <stdio.h>
#include <stdlib.h>

int main()
{
    int** M = new int *[2];
    M[0] = new int[5];
    M[1] = new int[5];

    int** M2 = new int *[2];
    M2[0] = new int[5];
    M2[1] = new int[5];

    for (int i=0;i<5;i++){
        M[0][i] = i;
        M[1][i] = 5+i;
    };

    for (int l=0; l<2; l++){
        for (int m=0; m<5; m++){
            *(*(M2 + (1 - l)) + (4 - m)) = *(*(M + l) + m);
        };
    };
}
