#include <bits/stdc++.h>

using namespace std;

bool check(string part_S, string T){
	for (int i=0; i<T.size(); i++){
		if ((part_S[i] != '?') && (part_S[i] != T[i])){
			return false;
		}
	}
	return true;
}

string merge(string S, string T, int left){
	for (int i=0; i<S.size(); i++){
		if (S[i] == '?'){
			S[i] = 'a';
		}
	}

	for (int j=0; j<T.size(); j++){
		S[j + left] = T[j];
	}

	return S;
}

int main(){
	string S;
	string T;

	cin >> S;
	cin >> T;

	if (S.size() < T.size()){
		cout << "UNRESTORABLE" << endl;
	}
	else{
		for (int i=S.size()-T.size(); i>=0; i--){
			string part_S = S.substr(i, T.size());
			if (check(part_S, T)){
				cout << merge(S, T, i) << endl;
				return 0;
			}
		}
		cout << "UNRESTORABLE" << endl;
	}

}