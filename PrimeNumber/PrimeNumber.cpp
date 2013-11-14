
#include <iostream>
using namespace std;

/*
 * 与えられた数が素数かどうか調べる
 * あるいは与えられた数までの素数を列挙する
 * 処理にかかった時間を計測しておくと、自分の技術向上に伴って処理時間が短くなっていくのがよくわかる
 */
bool is_prime(long n);

int main() {
	int num;
	cout << "Input Number " << endl; //
	cin >> num;
	cout << num << "は、";
	if(is_prime(num))
		cout << "素数でしょ" << endl;
	else
		cout << "素数ではない" << endl;
	return 0;
}

bool is_prime(long n){
	if(n < 2) return false;
	if(n == 2) return true;
	if(n%2==0) return false;
	long i = 0;
	for(i=2;i<n;i++){
		if(n%i==0) return false;
	}
	return true;
}
