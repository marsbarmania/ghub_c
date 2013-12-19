#include <iostream>
#include <cmath>
using namespace std;

struct myInt
{
  int val;
  myInt * next;
  myInt * prev;
};

typedef myInt *intCollection;

/*
  文字データを格納するのではなく、０から９までの数字をint型で扱う連結リストを考える。
  これを使えば、任意の大きさの正の整数を表す事ができる。
  例えば、１４９という数値をこの連結リストで表すと、最初のノードに１、次のノードに４、
  最後のノードに９を格納することになる。整数値を受け取ってこの形式を連結リストをつくる
  関数intToListを書いてみよう。
  ヒント：
  この連結リストは最後の要素から作っていく方が簡単にできるだろう。つまり受け取った値が
  １４９だったら、まずは９のnodeから作ってみよう
*/
intCollection intToList(int);

/*
  整数のリストを２つ受け取ってその和を同じ形式のリストで返す関数を書いてみよう
*/
intCollection sumList(intCollection, intCollection);

int listToInt(intCollection);

/* 表示する */
void showMyList(intCollection);

myInt* nodeAt(intCollection &, int);

int main(int argc, char const *argv[])
{
  int a = 149;
  //intToList(a);
  showMyList(intToList(a));

  cout << "--- Average ---" << endl;
  intCollection x = intToList(149), y = intToList(7);
  cout << " result= " << listToInt(sumList(x,y)) << endl;;

  return 0;
}

myInt* nodeAt(intCollection &ic, int position){
  myInt *node = ic;
  if(position == 0){
    return node;
  }else{
    for(int i=0; i < position; i++){
      node = node->next;
    }
    return node;
  }
}

int listToInt(intCollection ic){
  myInt *node = ic;
  int digit_num = 0, sum = 0;
  while(node!=NULL){
    node = node-> next;
    digit_num++;
  }
  //cout << "2番目: " << nodeAt(ic,0)->val << endl;
  for(int i=0;i<digit_num;i++){
    sum +=(nodeAt(ic,i)->val) * pow(10,digit_num-i-1);
  }
  return sum;
}

intCollection sumList(intCollection a, intCollection b){
  return intToList(listToInt(a) + listToInt(b));
}

intCollection intToList(int num){
  intCollection lc;

  if(num==0){
    myInt * node = new myInt;
    node->val=0;
    node->next = node->prev = NULL;
    lc = node;
    return lc;
  }

  int cnt = 0;
  myInt * temp = new myInt;

  // 桁数
  while(num > 0){
    myInt * node = new myInt;
    int r = num % 10;

    node->val = r;

    if(cnt==0){
      node->next = node->prev = NULL;
    }else{
      temp->prev = node;
      node->prev = NULL;
      node->next = temp;
    }

    temp = node;
    lc = node;

    num /= 10;
    cnt++;
  }

  delete temp;
  return lc;
}

void showMyList(intCollection ic){
  myInt * node = ic;
  while(node != NULL){
    cout << node->val;
    node = node->next;
  }
  cout << endl;
}
