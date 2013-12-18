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

/*
  removeCharsという関数を実装する
  位置と長さを指定して文字列の一部を取り除けるようにする
  例えば、removeChars(s1, 5, 3)は文字列の５番目から３文字を削除する。
  削除したノードのメモリはきちんと解放しておくこと。
*/

struct myChar
{
  char ch;
  myChar * next;
  myChar * prev;
};

typedef myChar *charcterList;

// 表示するだけ
void showString(charcterList cl);

// removeCharsメソッド
void removeChars(charcterList &, int,int);

// appendメソッド
void append(charcterList &,char);

// concatenateメソッド
void concatenate(charcterList &,charcterList &);

// characterAtメソッド
char characterAt(charcterList,int);

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

  cout << "removeCharsメソッド" << endl;
  charcterList cl3;
  myChar * node4 = new myChar;
  myChar * node5 = new myChar;
  myChar * node6 = new myChar;
  myChar * node7 = new myChar;
  myChar * node8 = new myChar;
  myChar * node9 = new myChar;
  myChar * node10 = new myChar;
  myChar * node11 = new myChar;
  myChar * node12 = new myChar;
  myChar * node13 = new myChar;

  node4->ch = 'N';
  node5->ch = 'a';
  node6->ch = 'K';
  node7->ch = 'a';
  node8->ch = 'S';
  node9->ch = 'h';
  node10->ch = 'i';
  node11->ch = 'M';
  node12->ch = 'a';
  node13->ch = 'N';

  cl3 = node4;
  node4->prev = NULL;
  node4->next = node5;
  node5->prev = node4;
  node5->next = node6;
  node6->prev = node5;
  node6->next = node7;
  node7->prev = node6;
  node7->next = node8;
  node8->prev = node7;
  node8->next = node9;
  node9->prev = node8;
  node9->next = node10;
  node10->prev = node9;
  node10->next = node11;
  node11->prev = node10;
  node11->next = node12;
  node12->prev = node11;
  node12->next = node13;
  node13->prev = node12;
  node13->next = NULL;

  showString(cl3);

  cout << "removeCharsメソッド => removeChars(s,5,3)" << endl;

  removeChars(cl3,5,3);

  showString(cl3);

  return 0;
}

void removeChars(charcterList &s, int position, int length){
  myChar * node = s;
  myChar * t1;
  myChar * t2;

  for(int i=1;i<position;i++){
    node = node->next;
  }

  // 一つ前のnodeのnextと削除直後のnodeのprevが変わる
  t1 = node->prev;
  for(int j=1;j<length;j++){
    myChar * delNode = node;
    node = node->next;
    delete delNode;
  }

  t2 = node->next;
  t1->next = t2;
  t2->prev = t1;
}

void showString(charcterList cl){
  myChar * node = cl;
  while(node != NULL){
    cout << node->ch;
    node = node->next;
  }
  cout << endl;
}

// appendメソッド：文字をリストの末尾に追加
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

// concatenateメソッド
void concatenate(charcterList &s1, charcterList &s2){
  charcterList copied = s2;

  myChar * node = copied;

  while(node != NULL){
    append(s1,node->ch);
    node = node->next;
  }
  copied = NULL;
}

// 参照だけ
char characterAt(charcterList cl, int position){

  myChar * node = cl;

  for(int i=0;i<position;i++){ node = node->next;}

  return node->ch;
}

