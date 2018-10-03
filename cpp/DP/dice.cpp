#include <bits/stdc++.h>

using namespace std;

vector<int> factorization(long long D){
	vector<int> fact = {0, 0, 0, 0};

	while (D % 2 == 0){
		fact[0] += 1;
		D = D / 2;
	}

	while (D % 3 == 0){
		fact[1] += 1;
		D = D / 3;
	}

	while (D % 5 == 0){
		fact[2] += 1;
		D = D / 5;
	}

	if (D != 1){
		fact[3] += 1;
	}
	
	return fact;
}

int main(){
	int N;
	long long D;
	cin >> N >> D;

	vector<int> fact = factorization(D);

	if (fact[3] == 1){
		cout << 0 << endl;
		return 0;
	}

	int A = fact[0];
	int B = fact[1];
	int C = fact[2];


	double dp[N+1][A+1][B+1][C+1];

	//initialization

	for (int a=0; a<=A; a++){
		for (int b=0; b<=B; b++){
			for (int c=0; c<=C; c++){
				dp[0][a][b][c] = 0;
			}
		}
	}
	dp[0][0][0][0] = 1;

	//DP
	for (int n=0; n<N; n++){
		for (int a=0; a<=A; a++){
			for (int b=0; b<=B; b++){
				for (int c=0; c<=C; c++){
					dp[n+1][a][b][c] = dp[n][a][b][c];
					if (c >= 1){
						dp[n+1][a][b][c] += 1.0/6*dp[n][a][b][c-1];
					}
					if (b >= 1){
						dp[n+1][a][b][c] += 1.0/3*dp[n][a][b-1][c];
						if (a >= 1){
							dp[n+1][a][b][c] += 1.0/6*dp[n][a-1][b-1][c];
						}
					}
					if (a >= 1){
						dp[n+1][a][b][c] += 1.0/2*dp[n][a-1][b][c];
						if (a >= 2){
							dp[n+1][a][b][c] += 1.0/6*dp[n][a-2][b][c];
						}
					}

				}
			}
		}
	}

	double ans=0;

	for (int n=0; n<=N; n++){
		ans += dp[n][A][B][C];
	}

	cout << ans << endl;


}