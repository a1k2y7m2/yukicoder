#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;

	if (s.at(0) != 'A'){
		cout << "WA" << endl;
		return 0;
	}

	int Ccount = 0;

	for (int i=1; i<s.size(); i++){
		if ((s.at(i) == 'C') && (i>=2) && (i<=s.size()-2)){
			Ccount++ ;
		}else if (isupper(s.at(i))){
			cout << "WA" << endl;
			return 0;
		}
	}

	if (Ccount == 1){
		cout << "AC" << endl;
		return 0;
	}else{
		cout << "WA" << endl;
		return 0;
	}

}