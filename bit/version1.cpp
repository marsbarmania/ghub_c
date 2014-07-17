#include <iostream>
using namespace std;

/*
整数変数中のビットをカウントするプログラムとしては、
プログラマーなら誰でも以下のようなプログラムが反射的に考えつくはず。
ただこのアルゴリズムは非常に大きな時間コストが掛かるダメアルゴリズムだ
*/

int countofbit1(int bits)
{
  int count = 0;
  int mask = 1;
  for(; mask!=0; mask=mask<<1){
    if(bits & mask)
      count++;
  }
  return count;
}

int main(int argc, char const *argv[])
{
  /* code */
  cout << countofbit1(0)<<endl;
  cout << countofbit1(1)<<endl;
  cout << countofbit1(2)<<endl;
  cout << countofbit1(3)<<endl;
  cout << countofbit1(4)<<endl;

  return 0;
}
