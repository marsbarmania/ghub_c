//============================================================================
// Name        : lcgs.cpp
// Version     : 線形合同法
//============================================================================

#include <iostream>
using namespace std;

/*
 * 漸化式
 * Xn+1 = (A x Xn + B) mod M
 * A、B、Mは定数で、M>A、M>B、A>0、B≥0
 */

/*
 * 線形合同法を用いて0<=x<1の範囲の乱数を発生させるプログラムを作成せよ。
 * M＝65536(=2^16),A=997,B=1,Xの初期値を12345として100個の乱数を発生させ,
 * その値と平均を出力しなさい
 */
void lcgs();

int main() {
	cout << "!Linear congruential generators!";
	cout << endl;
	lcgs();
	return 0;
}

/*
 *  [](){}() ;
 *  ------------------
 *  []  //  [ lambda-capture ]
 *  ()  //  ( parameter-declaration-clause )
 *  {}  //  compound-statement
 *  ()  //  Function call expression
 *  ------------------
 */
void lcgs(){
	int a = 997, b=1, m=65536, x = 12345,i,sum=0;

	for(i=0;i<100;i++){
		x = (a*x + b) % m;
		sum += x;
		cout << x << ", ";
		if(i%10==9)
			cout << endl;
	}
	cout << "平均値：" << (float)sum/m/i << endl;
}
