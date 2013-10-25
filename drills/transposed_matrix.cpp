#include <iostream>
using namespace std;

/*
 * 入力例
 * 1 2 3
 * 4 5 6
 * 7 8 9
 *
 * 出力例
 * 1 4 7
 * 2 5 8
 * 3 6 9
 *
 *１，５，９を線で結んだとすると、線対称な並びになっているのが分かると思う。
 *理屈は、2次元配列を2個用意して、片方の配列に数字を入れて、
 *もう片方の配列に転置した中身を入れればOK。
 *1つ目に、入力した行列を出力して、2つ目に転置した行列を出力する
 */

void set_transposed(int x[][3],int y[][3]);
void disp_array(int x[][3]);

int main() {
  cout << "Transposed Matrix ---> " << endl;
  int x[][3] = {{1,2,3},{4,5,6},{7,8,9}};
  int y[3][3];
  set_transposed(x,y);
  return 0;
}

void set_transposed(int x[][3],int y[][3]){
  disp_array(x);
  //
  for(int i=0;i<3;i++){
    for(int j=0;j<3; j++){
      y[j][i] = x[i][j];
    }
  }
  cout << "------ after ------" << endl;
  disp_array(y);
}

void disp_array(int x[][3]){
  for(int i=0; i < 3; i++){
    for(int j=0;j<3; j++){
      cout << x[i][j] << ", ";
    }
    cout << endl;
  }
}
