#include <iostream>
#include <ctime> // for time()
#include <cstdlib> // for srand(), rand()
using namespace std;

#define MIN 0
#define MAX 10

int main() {

  /*
   * srand関数は rand関数で発生させる擬似乱数の発生系列を変更します。
   * srand関数の引数seedに同じ数値を与えると、rand関数は同じ繰返しで擬似乱数を発生させます。
   * たとえば、下の使用例１では同じ seed で10回 srand関数を呼んでいますが、
   * 結果を見ると、10回とも同じ繰返しでrand関数は擬似乱数を発生させています。
   * また、srand関数を呼ばずにrand関数を実行した場合には、
   * srand関数でseedに１を設定したことと同じになり、
   * プログラムを何度実行しても同じ繰り返しで擬似乱数を発生します
   *
   * プログラムを実行するたびに異なる系列で擬似乱数を発生させるには、通常seedに現在時刻を設定します。
   * 現在時刻はtime関数で取得します。使用例２では現在時刻を設定して
   * srand関数を呼んでから、10回×10回 rand関数を呼んでいます。
   * 結果を見ると、不規則に擬似乱数を発生させていますね。
   * 現在時刻は同じ値が存在することはありませんので、
   * seedに現在時刻を設定すればプログラムを実行するたびに異なる系列で擬似乱数を発生させることができるのです。
   *
   * 【引数】
   * unsigned seed　：　擬似乱数の発生系列を変更する種。
   * 同じ数値を設定すると同じ繰返しでrand関数は擬似乱数を発生する。
   */
  srand(time(NULL)); // 現在時刻を乱数の種の設定
  int lucky = MIN + rand() % (MAX - MIN); // MIN以上MAX未満の乱数を生成
  //cout << "生成した乱数は" << lucky << "です。" << endl;
  int guessed;

  while(1){
    cout << "0~10の整数を入力して---> " << endl;
    cin >> guessed;
    cout << "入力値は" << guessed << endl;

    if(guessed==lucky) break;

    if(guessed > lucky)
      cout << "残念！もっと小さい数値を入力して--->" << endl;
    else if(guessed < lucky)
      cout << "残念！もっと大きな数値を入力して--->" << endl;
  }
  cout << "正解しました！ラッキーナンバーは " << lucky << "でした" << endl;
  /*
  for (int i = 0; i< 100; i++) {
    cout << MIN + rand() % (MAX - MIN) << endl;
  }
  */

  return 0;
}
