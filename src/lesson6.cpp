#include "lesson6.h"

#include <algorithm>

int Distinct(vector<int> &A) {
    int i=0, N=A.size(), count=1;
    if( N == 0 )
        return 0;

    sort(A.begin(), A.end());
    for( i=1; i < N; i++ ) {
        if( A[i] != A[i-1] )
            count++;
    }
    return count;
}

int MaxProductOfThree(vector<int> &A) {
    int N=A.size(), ret1, ret2;

    sort(A.begin(), A.end());
    ret1 = A[0] * A[1] * A[N-1];
    ret2 = A[N-3] * A[N-2] * A[N-1];

    if( ret1 > ret2 )
        return ret1;
    else
        return ret2;
}

int NumberOfDiscIntersections(vector<int> &A) {
    int i=0, j=0, N=A.size(), count=0, intersection=0;
    vector<int64_t> left, right;
    left.reserve(N);
    right.reserve(N);

    for( i=0; i < N; i++ ) {
        left.push_back((int64_t)i - A[i]);
        right.push_back((int64_t)i + A[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for( i=0; i < N; i++ ) {
        while( left[j] <= right[i] && j < N ) {
            j++;
            intersection++;
        }

        intersection--;
        count += intersection;

        if( count > 10000000 )
            return -1;
    }

    return count;
}

int Triangle(vector<int> &A) {
    int i=0, N=A.size();
    if( N < 3 )
        return 0;

    sort(A.begin(), A.end());
    for( i=0; i < N-2; i++ ) {
        if( (int64_t)A[i] + (int64_t)A[i+1] > (int64_t)A[i+2] )
            return 1;
    }

    return 0;
}
