#include <iostream>
using namespace std;
/*
ビットを数える最適化されたアルゴリズム。
このアルゴリズムではループ・条件分岐がないばかりか、剰余命令まで消失している。
現在のスーパースカラープロセッサでは演算を畳み込めるので、
CPU にビルトインしたビットカウント命令よりもこのアルゴリズムを用いた方が
高速に処理ができると思われる。
*/
int countofbit5(long bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}
