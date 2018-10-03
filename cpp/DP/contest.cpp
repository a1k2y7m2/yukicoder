#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	int P[N];
	int max_P = 0;

	for (int n=0; n<N; n++){
		cin >> P[n];
		max_P += P[n];
	}

	bool dp[N+1][max_P+1];

	//initialize
	for (int n=0; n<=N; n++){
		dp[n][0] = true;
	}

	for (int p=1; p<=max_P; p++){
		dp[0][p] = false;
	}

	for (int n=0; n<N; n++){
		for (int p=1; p<=max_P; p++){
			if (dp[n][p] || dp[n][p-P[n]]){
				dp[n + 1][p] = true;
			}else{
				dp[n + 1][p] = false;
			}
		}
	}

	int ans = 0;
	for (int p=0; p<=max_P; p++){
		if (dp[N][p]){
			ans += 1;
		}
	}

	cout << ans << endl;
}