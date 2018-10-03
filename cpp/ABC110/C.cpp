#include <bits/stdc++.h>

using namespace std;

int main(){
	string S;
	string T;

	cin >> S;
	cin >> T;

	string alp = "abcdefghijklmnopqrstuvwxyz";

	for (int a=0; a<alp.size(); a++){
		vector<int> S_id;
		vector<int> T_id;
		for (int i=0; i<S.size(); i++){
			if (alp[a] == S[i]){
				S_id.push_back(i);
			}
		}

		if (S_id.size() == 0){
			continue;
		}

		char target = T[S_id[0]];
		for (int j=0; j<T.size(); j++){
			if (target == T[j]){
				T_id.push_back(j);
			}
		}

		//check
		if (S_id != T_id){
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
}