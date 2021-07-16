#include "lesson5.h"

#include <map>
#include <memory.h>

int CountDiv(int A, int B, int K) {
    if( K == 0 )
        return 0;

    if( A == B )
        return A % K == 0 ? 1 : 0;

    int q = A/K;

    if( A % K == 0 )
        q--;

    return B/K - q;
}

vector<int> GenomicRangeQuery(string &S, vector<int> &P, vector<int> &Q) {
    int N=S.length(), M=P.size();
    int p, q;
    int i, j, counts[5] = {0,};
    int (*impacts)[5] = new int[N+1][5];
    std::map<char, int> gen {{'A',1}, {'C',2}, {'G',3}, {'T',4}};
    std::vector<int> ret;
    ret.reserve(M);

    memset(impacts, 0, sizeof(int) * (N+1) * 5);

    for( i=0; i < N; i++ ) {
        counts[gen[S.at(i)]]++;
        memcpy(impacts[i+1], counts, sizeof(int)*5);
    }

    for( i=0; i < M; i++ ) {
        p = P[i];
        q = Q[i];

        if( p == q ) {
            ret.push_back(gen[S.at(p)]);
            continue;
        }

        for( j=1; j < 4; j++ ) {
            if( impacts[p][j] != impacts[q+1][j] )
                break;
        }
        ret.push_back(j);
    }

    delete[] impacts;
    return ret;
}