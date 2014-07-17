#include <iostream>
using namespace std;

/*このアルゴリズムでは立っているビットが疎な場合にはかなり素早く収束する。*/
int countofbit3(int bits)
{
    int num  = 0;

    for ( ; bits != 0 ; bits &= bits - 1 ) {
        num++;
    }

    return num;
}
