#include "lesson4.h"

#include <memory.h>

int FrogRiverOne(int X, vector<int> &A) {
    int i=0, count=0, N=A.size();
    char check[X];
    memset(check, 0, X);

    for( i=0; i < N; i++ ) {
        if( check[A[i]-1] == 0 ) {
            check[A[i]-1] = 1;
            count++;
        }

        if( count >= X )
            return i;
    }

    return -1;
}

vector<int> MaxCounters(int N, vector<int> &A) {
    int i=0, max=0, last_max=0;
    vector<int> ret(N, 0);

    for( int a: A ) {
        if( a <= N ) {
            if( last_max > ret[a-1] )
                ret[a-1] = last_max + 1;
            else
                ret[a-1]++;

            if( ret[a-1] > max )
                max = ret[a-1];
        } else {
            last_max = max;
        }
    }

    for( i=0; i < N; i++ ) {
        if( ret[i] < last_max )
            ret[i] = last_max;
    }

    return ret;
}

int MissingInteger(vector<int> &A) {
    int i=0, N=A.size();
    char check[1000000] = {0,};

    if( N < 1 )
        return 1;

    for( int a: A ) {
        if( a < 1 )
            continue;
        check[a-1] = 1;
    }

    for( i=0; i < N; i++ )
        if( check[i] == 0 )
            break;

    return i+1;
}

int PermCheck(vector<int> &A) {
    int N=A.size();
    char check[N], ans[N];
    memset(check, 0, N);
    memset(ans, 1, N);

    for( int a: A ) {
        if( a > N )
            return 0;

        if( check[a-1] == 1 )
            return 0;

        check[a-1] = 1;
    }

    if( memcmp(check, ans, N) == 0 )
        return 1;
    return 0;
}
