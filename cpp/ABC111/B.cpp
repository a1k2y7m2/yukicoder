#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;

	int a=1;

	while (N > a*111){
		a += 1;
	}

	cout << a*111 << endl;
}