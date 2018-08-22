//blackfriday at kattis. 0.00s
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	map<int, int> scores;
	unordered_map<int, int> indices; //might as well use a vector for indexing, but this works too.

	int current;
	bool loser = true;
	for(int i = 1; i <= n; i++){
		cin >> current;
		scores[-current]++; 
		indices[current] = i;
	}
	
	for(map<int, int>::iterator it = scores.begin(); it != scores.end(); ++it){
		if((*it).second  == 1){
			cout << indices[-(*it).first] << "\n";
			loser = false;
			break;
		}
	}
	if(loser) cout << "none\n";
	return 0;
}
