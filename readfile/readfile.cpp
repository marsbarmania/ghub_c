/*
 * 引数としてファイル名を入力し、
 * そのファイルの内容を表示するプログラムを作れ。
 */
#include <iostream>
#include <fstream>

using namespace std;

int main(){
  char infile[30], buf[512];

  cout << "file名を入力して" << endl;

  cin >> infile;

  ifstream ifs(infile);

  ofstream ofs("output.txt");

  while(ifs.getline(buf,sizeof(buf))){
    ofs << buf << endl;
  }

  return 0;
}
