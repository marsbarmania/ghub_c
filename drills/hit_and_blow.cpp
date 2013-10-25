#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
using namespace std;

/*
 * これはｎ桁の数を探すゲームです。適当な数を入れると桁も数字もあっていれば「Hit」とし
 * その個数が、数字はあっているが桁が異なっていれば「Blow」としてその個数が出力されます。
 * それを繰り返すことで答えを探すことができます。
 * このゲームを作成しなさい。答えの数は乱数を使って毎回別の答えを用意しましょう。
 *
 * 具体的には
 * 正解が1234だとして
 * 4321　と入力　4blow
 * 1245　と入力　2hit　1blow
 * なおルール上4422などのゾロ目の正解は出ないようにしましょう。
 * また、先頭が0だとn桁の数字じゃなくなるのでせっかくなので0は発生させないようにしましょう。
 */

string luck_number(int);
void show_hb_count(string, string);
string int2string(int);

#define DIGIT_NUM 4
int main() {
  string lucky = luck_number(DIGIT_NUM);
  string guess;
  cout << "! Hit & Blow !" << endl;
  cout << "桁設定：4桁の整数を入力 ---> ";
  //cin >> guess;
  getline(cin,guess);

  show_hb_count(lucky,guess);
  return 0;
}

void show_hb_count(string lucky, string input){
  int i,hit=0,blow=0;
  for(i=0; i<lucky.size(); i++){
    //cout << typeid(lucky[i]).name() << " : " << typeid(input[i]).name() << " => " << endl;
    if(strcmp(&lucky[i],&input[i])==0)
      hit++;
    else
      blow++;
  }
  cout << input << "と入力 ";
  if(hit>0)
    cout << hit << "hit ";
  if(blow>0)
    cout << blow << "blow";
  cout << "  正解は" << lucky << endl;

}

string luck_number(int count){
  int i = 0;
  string s = "";
  srand(time(NULL));
  while(i < count){
    // 9桁まで
    int rnd = rand() % 10;
    if(i==0 && rnd == 0){
      continue;
    }else{

//      cout << s << " = " << IntToString(rnd) << " ?: ";
//      cout << s.find(int2string(rnd)) << endl;
      string tmp = int2string(rnd);
      string::size_type index = s.find(tmp);
      if(index==string::npos){
        s += tmp;
        i++;
      }else{
        continue;
      }
    }
  }
  //cout << atoi(s.c_str()) << endl;
  return s;
}

string int2string(int number){
  stringstream ss;
  ss << number;
  return ss.str();
}

void shuffle(){
  cout << "-- Shuffle --" << endl;
}
