#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;

	int W[N];

	vector<int> W_pile;

	for (int n=0; n<N; n++){
		cin >> W[n];
	}

	W_pile.push_back(W[0]);

	for (int n=1; n<N; n++){
		bool flag = false;
		for (int i=0; i<W_pile.size(); i++){
			if (W_pile[i] >= W[n]){
				W_pile[i] = W[n];
				flag = true;
				break;
			}
		}
		if (!flag){
			W_pile.push_back(W[n]);
		}
	}

	cout << W_pile.size() << endl;

}