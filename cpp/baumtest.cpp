#include <bits/stdc++.h>

using namespace std;

// Global Variance

vector<int> visited;
vector<vector<bool>> adj;

int check = 1;

int vector_finder(vector<int> vec, int number) {
	auto itr = find(vec.begin(), vec.end(), number);
	size_t index = distance( vec.begin(), itr );
	if (index != vec.size()) { // 発見できたとき
		return 1;
	}
	else { // 発見できなかったとき
		return 0;
	}
}

void dfs(int x, int prev){
	for (int vis: visited){
		if (vis == x){
			check = 0;
			return;
		}
	}

	visited.push_back(x);
	for (int n=0; n<adj.size(); n++){
		if (adj[x][n] && n != prev){
			dfs(n, x);
		}
	}
	return;
}

int not_close(int start){
	int ans = 0;
	dfs(start, -1);
	ans += check;

	while (visited.size() != adj.size()){
		for (int next=0; next<adj.size(); next++){
			if (vector_finder(visited, next) == 0){
				dfs(next, -1);
				break;
			}
		}
		ans += check;
	}

	return ans;
}


int main(){
	int N;
	int M;
	int u;
	int v;

	cin >> N >> M;
	adj = vector<vector<bool>>(N, vector<bool>(N, false));

	for (int m=0; m<M; m++){
		cin >> u >> v;
		adj[u-1][v-1] = true;
		adj[v-1][u-1] = true;
	}

	cout << not_close(0) << endl;
}