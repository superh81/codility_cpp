#include "lesson7.h"

#include <stack>

int Brackets(string &S) {
    stack<char> nested;

    for( char c: S ) {
        if( c == '(' || c == '{' || c == '[' )
            nested.push(c);
        else {
            if( (c == ')' && nested.top() != '(') ||
                (c == '}' && nested.top() != '{') ||
                (c == ']' && nested.top() != '[') )
                return 0;
            else
                nested.pop();
        }
    }

    if( nested.size() > 0 )
        return 0;

    return 1;
}

int Fish(vector<int> &A, vector<int> &B) {
    int i=0, N=A.size();
    stack<int> fish, updown;

    fish.push(A[0]);
    updown.push(B[0]);

    for( i=1; i < N; i++ ) {
        if( B[i] == 1 ) {
            fish.push(A[i]);
            updown.push(B[i]);
            continue;
        }

        while( !updown.empty() && updown.top() == 1 ) {
            if( A[i] > fish.top() ) {
                fish.pop();
                updown.pop();
            } else {
                break;
            }
        }

        if( updown.empty() || updown.top() == 0) {
            fish.push(A[i]);
            updown.push(B[i]);
        }
    }

    return fish.size();
}

int Nesting(string &S) {
    stack<char> nested;

    for( char c: S ) {
        if( c == '(' )
            nested.push(c);
        else {
            if( c == ')' && nested.top() != '(' )
                return 0;
            else
                nested.pop();
        }
    }

    if( nested.size() > 0 )
        return 0;

    return 1;
}

int StoneWall(vector<int> &H) {
    int i=0, N=H.size(), h=0, count=0;
    stack<int> wall;

    for( i=0; i < N; i++ ) {
        h = H[i];
        while( !wall.empty() && h < wall.top() )
            wall.pop();

        if( wall.empty() || h > wall.top() ) {
            wall.push(h);
            count++;
        }
    }

    return count;
}
