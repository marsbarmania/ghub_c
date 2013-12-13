#include <iostream>
using namespace std;

// 動的に確保した文字列を使って、replaceString関数をつくる
// パラメータ：source target replaceText、すべてarrayString型
// sourceに登場するすべてのtargetをreplaceTextに置換する
// source=abcdabee targt=ab replaceText=xyz
// sourceが示す配列の中身が、xyzcdxyzee

typedef char* arrayString;

int length(arrayString s){
  int n=0;
  for(;*(s+n)!= 0;){ n++;}
  return n;
}


bool compString(arrayString a, arrayString b){
  int len_a = length(a), len_b = length(b);

  if(len_a == len_b){
    for(int i=0;i<len_a;i++){
      if(a[i] != b[i]) return false;
    }
  }else{
    return false;
  }
  return true;
}

void append(arrayString &s, char ch){
  int oldLength = length(s);
  arrayString newS = new char[oldLength + 2];

  for(int i=0; i < oldLength; i++)
    newS[i] = s[i];
  newS[oldLength] = ch;
  newS[oldLength+1] = 0;
  delete[] s;
  s = newS;
}

void concatenate(arrayString &s1, arrayString &s2){
  int s1_OldLength = length(s1);
  int s2_OldLength = length(s2);
  int s1_NewLength = s1_OldLength + s2_OldLength;
  arrayString newS = new char[s1_NewLength + 1];
  for(int i=0; i<s1_OldLength; i++)
    newS[i] = s1[i];
  for(int i=0; i<s2_OldLength; i++)
    newS[s1_OldLength + i] = s2[i];
  newS[s1_NewLength] = 0;
  delete[] s1;
  s1 = newS;
}

void replaceString(arrayString &source, arrayString target, arrayString replaceText){
  //cout << source << endl;
  int i,num = 0;
  int len = length(target);
  arrayString replaced = new char[1];
  replaced[0] = 0;

  while(*(source + num) != 0){
    arrayString current = new char[len+1];
    for(i=0;i<len;i++){
      current[i] = source[num+i];
    }
    current[len] = 0;

    //cout <<"now: "<< current << endl;

    if(compString(current,target)){
      //cout << "一致：" << endl;
      concatenate(replaced,replaceText);
      num += len;
    }else{
      append(replaced,source[num]);
      num++;
    }

    delete[] current;
  }
  delete[] source;
  source = replaced;
  //cout << "replaced= " << replaced << endl;
}

int main(int argc, char const *argv[])
{
  /* code */
  arrayString c = new char[9];
  c[0] = 'a';
  c[1] = 'b';
  c[2] = 'c';
  c[3] = 'd';
  c[4] = 'a';
  c[5] = 'b';
  c[6] = 'e';
  c[7] = 'e';
  c[8] = 0;

  arrayString t = new char[3];
  t[0] = 'a';
  t[1] = 'b';
  t[2] = 0;

  arrayString r = new char[4];
  r[0] = 'x';
  r[1] = 'y';
  r[2] = 'z';
  r[3] = 0;

  cout << "start: " << c << endl;
  replaceString(c,t,r);
  cout << "result: " << c << endl;

  return 0;
}
