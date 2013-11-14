#include <iostream>
using namespace std;

/*
 * ルールは以下の通り
 * 1から順番に数を表示する
 * その数が3で割り切れるなら"Fizz"、5で割り切れるなら"Buzz"、
 * 両方で割り切れるなら"FizzBuzz"と表示する
 *
 * 要するに"1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz ･･･"と出力される
 */
void fizz_buzz(long);


int main() {
	long n;
	cout << "--- Input FizzBuzz Number---" << endl;
	cin >> n;
	fizz_buzz(n);
	return 0;
}

void fizz_buzz(long n){
	for(long i=1; i <= n; i++){
		if(i % 3 == 0 || i % 5 == 0){
			if(i%3==0 && i%5==0){
				cout << "FizzBuzz ";
			}else if(i% 3==0){
				cout << "Fizz ";
			}else{
				cout << "Buzz ";
			}
		}else{
			cout << i << " ";
		}
	}
}
