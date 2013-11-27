// ファイルから指定された単語を探し、ファイル名、行数、その行を表示するプログラムを作れ。
// ただし、
// プログラムの第一引数として検索単語、第二引数からはファイル名(複数指定可能) とする。
#include <iostream>
//#include <sstream>
#include <fstream>
#include <string>
using namespace std;

const int BUFFSIZE = 80;
void search_word(string word,string *files);

int main(){
  string f[] = {"1.txt", "2.txt", "3.txt"};
  string w = "abc";
  search_word(w,f);
  return 0;
}

void search_word(string word,string *files){
  int n = 0;
  char buf[BUFFSIZE];

  while(files[n] != ""){

    ifstream infile(files[n]);
    int line_num = 0;
    while(infile.getline(buf,BUFFSIZE)){
      line_num++;
      if(word==buf){
        cout << "Found same string in " << *(files+n) << " ";
        cout << "Line: " << line_num << endl;
      }
    }
    n++;
  }
}
