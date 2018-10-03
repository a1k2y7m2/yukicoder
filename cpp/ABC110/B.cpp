#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	int M;
	int X;
	int Y;

	cin >> N >> M >> X >> Y;
	vector<int> X_city(N+1, X);
	vector<int> Y_city(M+1, Y);

	for (int n=0; n<N; n++){
		cin >> X_city[n+1];
	}

	for (int m=0; m<M; m++){
		cin >> Y_city[m+1];
	}

	int X_max;
	int Y_min;

	X_max = *max_element(X_city.begin(), X_city.end());
	Y_min = *min_element(Y_city.begin(), Y_city.end());

	//cout << X_max << endl;
	//cout << Y_min << endl;

	if (X_max < Y_min){
		cout << "No War" << endl;
	}
	else{
		cout << "War" << endl;
	}
}