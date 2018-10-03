#include <bits/stdc++.h>

using namespace std;

int main(){
	int A;
	int B;
	int C;
	int ans;

	cin >> A >> B >> C;
	vector<int> X(3);

	if (A >= B){
		if (B >= C){
			X[0] = A;
			X[1] = B;
			X[2] = C;
		}
		else if (C >= A){
			X[0] = C;
			X[1] = B;
			X[2] = A;
		}
		else{
			X[0] = A;
			X[1] = B;
			X[2] = C;
		}
	}
	else{
		if (A >= C){
			X[0] = B;
			X[1] = A;
			X[2] = C;
		}
		else if (C >= B){
			X[0] = C;
			X[1] = B;
			X[2] = A;
		}
		else{
			X[0] = B;
			X[1] = C;
			X[2] = A;
		}
	}

	ans = X[0]*10 + X[1] + X[2];

	cout << ans << endl;
}