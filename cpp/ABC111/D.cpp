#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;

	int X[N];
	int Y[N];

	for (int n=0; n<N; n++){
		cin >> X[n] >> Y[n];
	}

	int amari = (X[0] + Y[0])%2;

	for (int n=0; n<N; n++){
		if ((X[N] + Y[N])%2 != amari){
			cout << -1 << endl;
			return 0;
		}
	}

	vector<int> sum;

	for (int n=0; n<N; n++){
		sum.push_back(abs(X[n]) + abs(Y[n]));
	}

	int max_sum = *max_element(sum.begin(), sum.end());

	int m = max_sum;
	vector<int> D(m, 1);

	cout >> m >> endl;
	for (int d : D){
		cout >> d;
	}



}