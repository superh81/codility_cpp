#include "lesson7.h"

#include <algorithm>
#include <map>

int Dominator(vector<int> &A) {
    int i=0, N=A.size(), dom=-1, count=0;

    if( N == 0 )
        return -1;
    if( N == 1 )
        return 0;

    vector<int> data(A);
    sort(data.begin(), data.end());

    for( i=1; i < N; i++ ) {
        if( data[i-1] == data[i] ) {
            count++;
        } else {
            if( count >= N/2 ) {
                dom = data[i-1];
                break;
            }
            count = 0;
        }
    }

    if( i == N )
        dom = data[i-1];

    if( count >= N/2 ) {
        for( i=0; i < N; i++ ) {
            if( A[i] == dom )
                return i;
        }
    }
    return -1;
}

int EquiLeader(vector<int> &A) {
    int i=0, N=A.size(), leader=A[0], max=1, count=0, ret=0;
    map<int, int> data;
    map<int, int>::iterator it;

    for( int a: A ) {
        it = data.find(a);
        if( it == data.end() )
            data.insert({a, 1});
        else {
            it->second++;
            if( it->second > max ) {
                leader = it->first;
                max = it->second;
            }
        }
    }

    if( max < N/2 )
        return 0;

    for( i=1; i < N; i++ ) {
        if( A[i-1] == leader )
            count++;

        if( count > i/2 && max-count > (N-i)/2 )
            ret++;
    }

    return ret;
}
