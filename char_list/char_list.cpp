#include <iostream>
using namespace std;

/*
  動的に確保した配列ではなく、文字の連結リストを使って文字列を実装してみよう。
  つまり１文字のデータを扱う連結リストを作る事になる。
  これを使えば、文字列の長さをのばす時に全体を作り直す必要がなくなる。
  まずはappend関数とcharacterAt関数を実装するところから始めて見よう。
*/

/*
  concatenate関数を実装する
  concatenate(s1, s2)のパラメータはいずれも連結リストの最初のノードへの
  ポインタになることに注意してほしい。この関数はs2の各ノードのコピーをつくり
  それをs1の最後に連結することになる。つまり、リストs1の最終ノードのnextフィールドから
  リストs2の先頭ノードを指すようにすればいいというわけではない。
*/

struct myChar
{
  char ch;
  myChar * next;
  myChar * prev;
};

typedef myChar *charcterList;

// 表示
void showString(charcterList cl){
  myChar * node = cl;
  while(node != NULL){
    cout << node->ch;
    node = node->next;
  }
  cout << endl;
}

// 末尾に追加
void append(charcterList &cl, char ch){
  myChar * node = cl;

  myChar *newCh = new myChar;
  newCh->ch = ch;
  newCh->next = NULL;

  // 末尾までいく
  while(node != NULL){
    //cout << node << endl;
    node = node->next;
    if(node->next->next==NULL){
      // cout << "break= " << node->next->ch << endl;
      node->next->next = newCh;
      newCh->prev = node->next->next;
      break;
    }
  }

}

void concatenate(charcterList &s1, charcterList &s2){
  charcterList copied = s2;
  // cout << "copied" << endl;
  // showString(copied);
  myChar * node = copied;
  while(node != NULL){
    append(s1,node->ch);
    node = node->next;
  }
  copied = NULL;
}

char characterAt(charcterList cl, int position){

  myChar * node = cl;

  for(int i=0;i<position;i++){ node = node->next;}

  return node->ch;
}

int main(int argc, char const *argv[])
{
  /* code */
  charcterList cl;

  myChar *node1 = new myChar;
  myChar *node2 = new myChar;
  myChar *node3 = new myChar;

  node1->ch = 't';
  node2->ch = 'e';
  node3->ch = 's';

  cl = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = NULL;

  node1->prev = NULL;
  node2->prev = node1;
  node3->prev = node2;

  node1 = node2 = node3 = NULL;

  cout << "now -> " << endl;
  showString(cl);

  append(cl,'t');
  showString(cl);

  append(cl,'+');


  cout << "2番目の文字は " << characterAt(cl, 2) << "です。" << endl;

  charcterList cl2;
  myChar * nodea = new myChar;
  myChar * nodeb = new myChar;
  myChar * nodec = new myChar;

  nodea->ch = 'M';
  nodeb->ch = 'A';
  nodec->ch = 'C';

  cl2 = nodea;
  nodea->next = nodeb;
  nodeb->next = nodec;
  nodec->next = NULL;

  nodea->prev = NULL;
  nodeb->prev = nodea;
  nodec->prev = nodeb;

  nodea = nodeb = nodec = NULL;

  cout << "--- string2 ---" << endl;
  showString(cl2);

  concatenate(cl,cl2);

  cout << "after concatenate" << endl;

  showString(cl);


  return 0;
}
