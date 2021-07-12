#include "lesson2.h"

vector<int> CyclicRotation(vector<int> &A, int K) {
    int N = (int)A.size();
    vector<int> ret;
    ret.reserve(N);

    if( N < 1 )
        return ret;

    while( K >= N )
        K -= N;

    copy(A.begin() + (N - K), A.end(), back_inserter(ret));
    copy(A.begin(), A.begin() + (N - K), back_inserter(ret));

    return ret;
}
