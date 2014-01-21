#include <iostream>
using namespace std;

// Q. Write a c program to accept n elements from user and reverse all elements.

#define S 50

int main(int argc, char const *argv[])
{
  int i, num, mid;
  int arr[S], tmp;
  cout << "Ener total number of element in array : " << endl;
  cin >> num;
  cout << "要素数：" << num << "個の配列を作成" << endl;
  cout << "[";
  for(i=0; i<num; i++){
    arr[i] = i;
    cout << i << ",";
  }
  cout << "]" << endl;

  mid = num/2;
  cout << "mid= " << mid << endl;
  for(i=0;i<mid;i++){
    /*swapping*/
    tmp = arr[i];
    arr[i] = arr[num-1-i];
    arr[num-1-i] = tmp;
  }

   cout << "[";
  for(i=0; i<num; i++){
    cout << arr[i] << ",";
  }
  cout << "]" << endl;

  return 0;
}
