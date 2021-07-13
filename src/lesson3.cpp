#include "lesson3.h"

int FrogJmp(int X, int Y, int D) {
    Y -= X;
    if( Y < 1 )
        return 0;

    return (int)((Y + D - 1) / D);
}

int PermMissingElem(vector<int> &A) {
    uint64_t sum1=0, sum2=0;
    size_t i=0, N=A.size();
    for( i=0; i < N; i++ ) {
        sum1 += A[i];
        sum2 += i;
    }
    sum2 += (2*N+1);

    return (int)(sum2-sum1);
}

int TapeEquilibrium(vector<int> &A) {
    int min=0x0fffffff, gap=0;
    int i=0, N=A.size();
    int front=A[0], rear=0;

    if( N == 1 )
        return A[0];

    for( i=1; i < N; i++ )
        rear += A[i];

    for( i=1; i < N; i++ ) {
        gap = GAP(front, rear);
        if( gap < min )
            min = gap;
        front += A[i];
        rear -= A[i];
    }

    return min;
}
