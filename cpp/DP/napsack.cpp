#include <bits/stdc++.h>

using namespace std;

// 指数時間アルゴリズム
int napsack(int n, int i, int v, int w){
	if (i == 0){
		return 0;
	}
	else if(i == 0){
		return 0;
	}

	if (i > w[n-1]){
		return max(napsack(n-1, i - w[n-1]) + v[n-1], napsack(n-1, i));
	}
	else{
		return napsack(n-1, i)
	}
}

//

int main(){
	int N;
	int W;

	cin >> N >> W;

	int v[N];
	int w[N];

	int dp[N+1][W+1];

	for (int n=0; n<N; n++){
		cin >> v[n] >> w[n];
	}

	for (int n=0; n<N; n++){
		dp[n][0] = 0;
	}

	for (int i=0; i<W; i++){
		dp[0][i] = 0;
	}

	for (int n=1; n<=N; n++){
		for (int i=1; i<=W; i++){
			if (i >= w[n-1]){
				dp[n][i] = max(dp[n-1][i - w[n-1]] + v[n-1], dp[n-1][i]);
			}
			else{
				dp[n][i] = dp[n-1][i];
			}
		}
	}

	cout << dp[N+1][W+1] << endl;
}