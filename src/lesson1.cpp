#include "lesson1.h"

int BinaryGap(int N) {
    bool valid=false;
    int count=0, max=0;

    for( int i=0; i < 32; i++, N >>= 1 ) {
        if( (N & 0x01) == 0x01 ) {
            if( valid ) {
                if( count > max )
                    max = count;
                count = 0;
            } else {
                valid = true;
            }
        } else {
            if( valid )
                count++;
        }
    }

    return max;
}
