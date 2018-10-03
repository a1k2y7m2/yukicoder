#include <bits/stdc++.h>

using namespace std;

typedef std::pair<int,int> ipair;
bool greaterPair(const ipair& l, const ipair& r){return l.second > r.second;}

int max_index(vector<int> vec){
	vector<int>::iterator iter = max_element(vec.begin(), vec.end());
	int index = distance(vec.begin(), iter);
	return index;
}

int main(){
	int N;

	cin >> N;
	int V[N];

	for (int n=0; n<N; n++){
		cin >> V[n];
	}

	vector<int> odd_vec;
	vector<int> even_vec;

	for (int n=0; n<(N/2); n++){
		odd_vec.push_back(V[2*n]);
		even_vec.push_back(V[2*n+1]);
	}

	vector<int> odd_count(100001, 0);
	vector<int> even_count(100001, 0);

	for (int o : odd_vec){
		++odd_count[o];
	}

	for (int e : even_vec){
		++even_count[e];
	}

	vector<ipair> odd_pair;
	vector<ipair> even_pair;

	for (int i=0; i<odd_count.size(); i++){
		odd_pair.push_back(ipair(i, odd_count[i]));
	}

	for (int i=0; i<even_count.size(); i++){
		even_pair.push_back(ipair(i, even_count[i]));
	}

	partial_sort(odd_pair.begin(), odd_pair.begin()+2, odd_pair.end(), greaterPair);
	partial_sort(even_pair.begin(), even_pair.begin()+2, even_pair.end(), greaterPair);

	int ans;

	if (odd_pair[0].first != even_pair[0].first){
		ans = N - odd_pair[0].second - even_pair[0].second;
	}
	else{
		ans = N - max(odd_pair[1].second + even_pair[0].second, odd_pair[0].second + even_pair[1].second);
	}

	cout << ans << endl;

}