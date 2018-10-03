#include <bits/stdc++.h>

using namespace std;

class lake_counting{
private:
	string check_Map[10][10];
	int visited[10][10];

public:
	lake_counting(string Map[10][10], int i, int j);
	int counting();
	void dfs(int x, int y);
	// ~lake_counting();
};

lake_counting::lake_counting(string Map[10][10], int I, int J){
	//copy
	for (int x=0; x<10; x++){
		for (int y=0; y<10; y++){
			check_Map[x][y] = Map[x][y];
			visited[x][y] = 0;
		}
	}
	check_Map[I][J] = "o";
}

int lake_counting::counting(){
	int count = 0;
	for (int i = 0; i<10; i++){
		for (int j = 0;j<10; j++){
			if (check_Map[i][j] == "o" && visited[i][j] == 0){
				dfs(i, j);
				count += 1;
			}
		}
	}
	return count;
}

void lake_counting::dfs(int x, int y){
	if (x < 0 || y < 0 || x >= 10 || y >= 10){
		return;
	}

	if (visited[x][y] == 1){
		return;
	}

	if (check_Map[x][y] == "x"){
		visited[x][y] = 1;
		return;
	}

	visited[x][y] = 1;

	vector<vector<int>> D = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	for (vector<int> d : D){
		dfs(x + d[0], y + d[1]);
	}

}

int main(){
	string Map[10][10];
	string line;
	string ans = "NO";

	for (int i=0; i<10; i++){
		cin >> line;
		for (int j=0; j<10; j++){
			Map[i][j] = line[j];
		}
	}

	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			if (Map[i][j] == "x"){
				lake_counting Lake(Map, i, j);
				if (Lake.counting() == 1){
					ans = "YES";
				}
			}
		}
	}

	cout << ans << endl;
}