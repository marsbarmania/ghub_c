#include <iostream>
using namespace std;

/* 配列をランダムに並べ替える */
// テンプレートを定義
template<typename T>

void shuffle(T arr[], int n){
  int i, rnd;
  T temp;
  srand(time(NULL));
  for(i=0;i<n;i++){
    rnd = rand() % n;
    temp = arr[i];
    arr[i] = arr[rnd];
    arr[rnd] = temp;
  }
}

void show_arr(char *a){
  for(int i=0; i <=26; i++){
    cout << a[i];
    if(i != 26) cout << ", ";
  }
  cout << endl;
}

int main() {
  int const CHAR_NUM = 256;

  char table[] = {'c','q','p','a','g','n','w','f','u','d','k','s','h','j','l','b','e','z','r','i','t','m','y','o','v','x'};
  shuffle(table, 26);
  //show_arr(table);
  char word[CHAR_NUM];
  cout << "半角英単語を入力 ---> " << endl;
  cin.getline(word,CHAR_NUM);
  cout << word << "という文字入力したね "<< endl;
  cout << "いまからバラバラにするわ。" << endl;

  for(int i=0 ; i < strlen(word); i++){
    // asciiコード値にするよ
    for(int n=0;n<26;n++){
      if(*(word+i) == *(table+n)){
        *(word+i) = static_cast<char>(n + 'a');
        break;
      }
    }
  }

  cout << "\"";
  for(int i=0 ; i < strlen(word); i++){
    cout << *(word+i);
  }
  cout << "\"" <<endl;
  char decoded[CHAR_NUM];

  cout << "出力された文字をもう一回キーボード（コピペ）で入力してくれ。元に戻すよ。" << endl << endl;
  cin.getline(decoded,CHAR_NUM);
  cout << "これでしょ。" << endl;
  for(int i=0 ; i < strlen(decoded); i++){
    // Spaceはasciiで32なので
    if(static_cast<int>(*(decoded+i))==32)
      cout << " ";
    cout << table[static_cast<int>(*(decoded+i))-'a'];
  }
  cout << endl;
  return 0;
}
