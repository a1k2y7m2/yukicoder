#include <bits/stdc++.h>

using namespace std;

int main(){
	int D, G;
	cin >> D >> G;
	vector<int> P(D);
	vector<int> C(D);

	for (int d=0; d<D; d++){
		cin >> P[d] >> C[d];
	}

	int min_solve = 1000;
	int score;
	int solve;
	int maxpro;
	int extra;

	//bit全探索, 完全に解く場合
	for (int bit=0; bit <(1<<D); bit++){
		score=0;
		solve=0;
		maxpro = -1;
		for (int i=0; i<D; i++){
			if (bit & (1 << i)){
				score += (i+1)*100*P[i];
				score += C[i];
				solve += P[i];
			}
			else{
				maxpro = i;
			}
		}

		if (score >= G){
			if (min_solve > solve) min_solve = solve;
		}else{
			if (maxpro >= 0){
				//extra = ceil((G-score)/((maxpro+1)*100));
				extra = (G-score+(maxpro+1)*100 - 1)/((maxpro+1)*100);
              	//cout << bit << " " << extra << endl;
				if (extra < P[maxpro]){
					solve += extra;
					if (min_solve > solve) min_solve = solve;			
				}
			}
		}
	}

	cout << min_solve << endl;

}