#include <iostream>
using namespace std;

bool is_leapyear(int);
int main() {
  int year;
  cout << "西暦を入力する" << endl;
  cin >> year;
  cout << year << "年は";
  if(is_leapyear(year))
    cout << "うるう年ですわ" << endl;
  else
    cout << "うるう年でないね" << endl;
  return 0;
}

/*
 * 1.西暦で示した年が4で割り切れる年は閏年です
 * 2.西暦で示した年が100で割り切れる年は閏年ではありません
 * 3.西暦で示した年が400で割り切れる年は閏年です
 */
bool is_leapyear(int num){
  if(num%400==0 || (num%4==0 && num % 100!=0)){
    return true;
  }else{
    return false;
  }

}
