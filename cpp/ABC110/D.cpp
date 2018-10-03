#include <bits/stdc++.h>

using namespace std;

long long mod = 1000000007;

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long waru(long long a, long long b){
	return ((a % mod) * (modpow(b, mod-2) % mod)) % mod;
}

vector<int> factorization(int M){
	int sqrt_M = (int)sqrt(M);
	vector<int> fact;

	for (int m=2; m<=sqrt_M; m++){
		int num = 0;
		while (M % m == 0){
			num += 1;
			M = M / m;
		}
		if (num != 0){
			fact.push_back(num);
		}
		if (M == 1){
			break;
		}
	}
	if (M != 1){
		fact.push_back(1);
	}
	return fact;
}

long long combination(int a, int b){
	long long bunbo = 1;
	long long bunshi = 1;
	for (int i=1; i <= b; i++){
		bunbo = ((bunbo % mod) * i) % mod;
	}
	for (int j=a; j>a-b; j--){
		bunshi = ((bunshi % mod) * j) % mod;
	}
	return waru(bunshi, bunbo);
}

int main(){
	int N;
	int M;
	cin >> N >> M;
	long long ans = 1;

	vector<int> fact;
	fact = factorization(M);

	for (int f : fact){
		// cout << f << endl;
		// cout << combination(f+N-1, f) << endl;
		ans = ((ans % mod) * (combination(f+N-1, f) % mod)) % mod;
	}

	cout << ans << endl;
}