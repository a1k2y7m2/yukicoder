#include <bits/stdc++.h>

using namespace std;

// Global Variance
vector<vector<bool>> maze;
vector<vector<int>> visited;

int bfs(vector<int> start, vector<int> goal){
	queue<vector<int>> Q;
	int minimum = 0;

	vector<vector<int>> D = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	visited[start[0]][start[1]] = 0;
	Q.push(start);


	while (!(Q.empty())){
		if (Q.front() == goal){
			return visited[goal[0]][goal[1]];
		}
		vector<int> pre = Q.front();
		Q.pop();
		for (vector<int> d : D){
			if((visited[pre[0] + d[0]][pre[1] + d[1]] == -1) && (maze[pre[0] + d[0]][pre[1] + d[1]])){
				visited[pre[0] + d[0]][pre[1] + d[1]] = visited[pre[0]][pre[1]] + 1;
				Q.push({pre[0] + d[0], pre[1] + d[1]});
			}

		}

	}
}

int main(){
	int R;
	int C;
	vector<int> start(2);
	vector<int> goal(2);
	string line;

	cin >> R >> C;
	cin >> start[0] >> start[1];
	cin >> goal[0] >> goal[1];

	start[0]--;
	start[1]--;
	goal[0]--;
	goal[1]--;

	maze = vector<vector<bool>>(R, vector<bool>(C, false));
	visited = vector<vector<int>>(R, vector<int>(C, -1));

	for (int r=0; r<R; r++){
		cin >> line;
		for (int c=0; c<C; c++){
			if (line[c] == '.'){
				maze[r][c] = true;
			}
		}
	}

	cout << bfs(start, goal) << endl;
}