//kattis disastrous downtime. 0.02s.
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int n, k, req, max, curr_count;
	cin >> n >> k;
	vector<pii> requests;
	
	while(n--){
		cin >> req;
		requests.push_back(make_pair(req, 1));
		requests.push_back(make_pair(req + 1000, -1));
	}
	sort(requests.begin(), requests.end());
	max = 0; curr_count = 0;
	for(auto it = requests.begin(); it != requests.end(); ++it){
		curr_count += (*it).second;
		if(max < curr_count) max = curr_count;
	}
	cout << (max + k - 1) / k << "\n";

	return 0;
}
