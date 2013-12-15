#include <iostream>
using namespace std;

/*
  removeRecord関数
  studentCollectionへのポインタと学生番号文字列をうけとり
  その学生番号の学生レコードをコレクションから取り除く
*/

struct listNode
{
  int studentNum;
  int grade;
  listNode * next;
  listNode * prev;
};

typedef listNode * studentCollection;

void addRecord(studentCollection &sc, int stuNum, int gr){
  listNode * newNode = new listNode;
  newNode->studentNum = stuNum;
  newNode->grade = gr;
  newNode->next = sc;
  newNode->next->prev = newNode;
  newNode->prev = NULL;
  sc = newNode;
}

void removeRecord(studentCollection &sc, int num){
  listNode *node = sc;

   while(node != NULL){
    if(node->studentNum == num){
      // cout << "削除して(" << node->studentNum << ")" << endl;
      // cout << "Nextをいまにするよ= " << node->next->studentNum << endl;
      // cout << "Prev = " << node->prev->studentNum << endl;
      node->prev->next = node->next;
      if(node->next==NULL){
        cout << "NULLだよ" << endl;
      }
      delete node;
      break;
    }else{
      node = node->next;
    }
  }
}

void show(studentCollection sc){
  listNode * node = sc;

  while(node != NULL){
    cout << node->studentNum << endl;
    node = node->next;
  }

}

int main(int argc, char const *argv[])
{
  studentCollection sc;

  listNode * node1 = new listNode;

  node1->studentNum = 1001;
  node1->grade = 78;

  listNode *node2 = new listNode;
  node2->studentNum = 1012;
  node2->grade = 93;

  listNode * node3 = new listNode;
  node3->studentNum = 1076;
  node3->grade = 85;

  sc = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = NULL;

  node1->prev = NULL;
  node2->prev = node1;
  node3->prev = node2;

  node1 = node2 = node3 = NULL;



  addRecord(sc,1019,98);
  addRecord(sc,1274,91);

  cout << "before ---- " << endl;
  show(sc);


  removeRecord(sc,1001);
  cout << "after ---- " << endl;
  show(sc);
  cout << endl << endl;

  return 0;
}
