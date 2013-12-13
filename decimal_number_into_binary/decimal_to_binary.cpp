#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int to_binary(int n){
  int r;
  string s;

  if(n==1) return n;

  while(true){
    r = n % 2;
    if(n==1){
      s += "1";
      break;
    }
    s += to_string(r);
    n /= 2;
  }
  // reverse
  reverse(s.begin(),s.end());
  return atoi(s.c_str());
}


int main(int argc, char const *argv[])
{
  int num;
  cout << "Input Number ->" << endl;
  cin >> num;
  cout << to_binary(num) << endl;
  return 0;
}
