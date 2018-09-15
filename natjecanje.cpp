#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int N, S, R;
	cin >> N >> S >> R;
	
	unordered_map<int, bool> damaged;
	vector<int> reserves (N + 2, 0);

	int inp;
	while(S--){
		cin >> inp;
		damaged[inp] = true;
	}
	
	while(R--){
		cin >> inp;
		if(damaged.find(inp) != damaged.end()){
			damaged.erase(inp);
			continue;
		}
		reserves[inp] = 1;
	}
	int count = 0;

	for(auto it = damaged.begin(); it != damaged.end(); ++it){
		if(reserves[(*it).first + 1]) reserves[(*it).first + 1] = 0;
		else if(reserves[(*it).first - 1]) reserves[(*it).first - 1] = 0;
		else{
			count++;
		}
	}
	cout << count << "\n";

	return 0;
}
