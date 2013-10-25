#include <iostream>
using namespace std;

int hanoi(int,char,char, char);

int main() {
  int n;
  cout << "Tower of Hanoi" << endl;
  cout << "適当なハノイ整数--> " << endl;
  cin >> n;
  hanoi(n,'A','B','C');
  return 0;
}

int hanoi(int n,char x,char y, char z){
  // n=0の場合
  // 何もしない
  // n > 0の場合
  // 1. n-1枚の円盤を柱xから柱zを柱yを利用して移す（n-1）ハノイを解く
  // 2. 次に1舞のえんばんを柱xから柱yに移動
  // 3. n-1枚の円盤を、柱zから柱yへ柱xを利用して移す（n-1）ハノイを解く
  if(n==0){
    // 何もしない
  }else{
    hanoi(n-1,x,y,z);
    cout << x << "->" << y << " ";
    hanoi(n-1,z,x,y);
  }
  return 0;
}
