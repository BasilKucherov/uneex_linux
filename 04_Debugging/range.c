#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int N, M=0, S=1;

    if (argc == 1) {
        printf("Usage: \n");
        printf(" range N - result [0, 1, ..., N-1]\n");
        printf(" range M N - result [M, M+1, ..., N-1]\n");
        printf(" range M N S - result [M, M+S, ..., N-1]\n");
        return 0;
    } else if (argc == 2) {
        N = atoi(argv[1]);
    } else if (argc == 3) {
        M = atoi(argv[1]);
        N = atoi(argv[2]);
    } else if (argc == 4) {
        M = atoi(argv[1]);
        N = atoi(argv[2]);
        S = atoi(argv[3]);
    } else {
        printf("Too many parameteres");
        return 1;
    }

    for(int i = M; i < N; i += S) {
        printf("%d\n", i);
    }
    return 0;
}
