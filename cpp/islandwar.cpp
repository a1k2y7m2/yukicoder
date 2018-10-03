#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A;
vector<bool> clear;

int max_index(vector<int> vec){
	vector<int>::iterator iter = max_element(vec.begin(), vec.end());
	int index = distance(vec.begin(), iter);
	return index;
}

vector<int> greedy(vector<int> bridge){
	int id = max_index(bridge);
	for (int m=0; m<clear.size(); m++){
		if (!clear[m] && (id >= A[m][0]-1) && (id < A[m][1]-1)){
			clear[m] = true;
			for (int i=A[m][0]-1; i<A[m][1]-1; i++){
				bridge[i] = bridge[i] - 1;
			}
		}
	}

	return bridge;
}

bool all_true(vector<bool> vec){
	for (int j=0; j<vec.size(); j++){
		if (!vec[j]){
			return false;
		}
	}
	return true;
}

int main(){
	int N;
	int M;
	int ans = 0;

	cin >> N >> M;
	A = vector<vector<int>>(N-1, vector<int>(2, -1));
	clear = vector<bool>(M, false);

	vector<int> bridge(N-1, 0);

	for (int m=0; m<M; m++){
		cin >> A[m][0] >> A[m][1];
	}

	for (int m=0; m<M; m++){
		for (int i=A[m][0]-1; i<A[m][1]-1; i++){
			bridge[i] = bridge[i] + 1;
		}
	}

	while (!all_true(clear)){
		bridge = greedy(bridge);
		ans += 1;
	}
	cout << ans << endl;
}