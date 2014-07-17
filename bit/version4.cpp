#include <iostream>
using namespace std;

// バージョン 4 ではループを使用しないでもビットカウント操作ができてしまっている。
int countofbit4(int bits)
{
    int num;

    num = (bits >> 1) & 03333333333;
    num = bits - num - ((num >> 1) & 03333333333);
    num = ((num + (num >> 3)) & 0707070707) % 077;

    return num;
}
