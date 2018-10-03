#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;

	int N = s.length();
	int num = atoi(s.c_str());
	int sum = 0;

	for (int bit=0; bit < (1<<(N-1)); bit++){
		int part_sum = 0; //1パターン内での和
		int resid = num; //計算用
		int quot; //商

		for (int j=N-2; j > -1; j--){
			if (bit & (1 << j)){
				quot = resid / pow(10, j+1);
				part_sum += quot;
				resid -= quot*pow(10, j+1);
			}
		}
		part_sum += resid;
		sum += part_sum;
	}
	cout << sum << endl;
}