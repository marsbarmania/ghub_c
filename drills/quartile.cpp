#include <iostream>
#include <string>
using namespace std;

const int ARRAY_SIZE = 10;

struct student{
  int grade;
  int studentID;
  string name;
};

void quartile(int*,size_t);

int compareGrade(const student *x,const student *y){
  return (x->grade < y->grade ? -1 : x->grade > y->grade ?  1 : 0);
}

int main() {
  student studentArray[ARRAY_SIZE] = {
      {87, 10001, "Fred"},
      {28, 10002, "Tom"},
      {100, 10003, "Alistair"},
      {78, 10004, "Sasha"},
      {84, 10005, "Erin"},
      {98, 10006, "Belinda"},
      {75, 10007, "Leslie"},
      {70, 10008, "Candy"},
      {81, 10009, "Aretha"},
      {68, 100010, "Veronica"}
  };

  qsort(studentArray,ARRAY_SIZE,sizeof(student),(int(*)(const void*, const void*))compareGrade);

  int i, x[ARRAY_SIZE];
  for(i=0; i<ARRAY_SIZE;i++){
    *(x+i)= studentArray[i].grade;
  }

  quartile(x,ARRAY_SIZE);
  return 0;
}

void quartile(int a[],size_t len){
  //構文 sizeof(array) / sizeof(array[0]) が成立するのは、
  //array の定義が同じスコープ内にある場合である。
  if(len % 2 == 0){
    int center = len/2;
    // 中央値
    cout << "中央値：" << (a[center-1] + a[center])/2;
    cout << " 第1四分位数：" << (a[center/2 -1] + a[center/2])/2;
    cout << " 第3四分位数：" << (a[center/2 + center] + a[center/2 + center +1])/2 << endl;
  }else{
    // 中央値インデックス
    int k = len/2;
    cout << "中央値：" << a[k] << " 第1四分位数："
       << a[(1+k)/2] << " 第3四分位数：" << a[(k+len)/2] << endl;
  }

}
