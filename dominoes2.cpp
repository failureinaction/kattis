//Dominoes2 at kattis. 0.01s.

#include <bits/stdc++.h>

using namespace std;
bitset<10001> visited; //global bitset to keep track of visited

void play(vector<vector<int>>& vii, int x){
	if(visited[x]) return;
	visited[x] = 1;
	for(vector<int>::iterator it = vii[x].begin(); it != vii[x].end(); ++it){
		play(vii,*it);
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--){
		int n, m, l;
		cin >> n >> m >> l;
		vector<vector<int>> indextofallvector (n + 1);
		visited = 0;
		int x, y;
		while(m--){
			cin >> x >> y;
			indextofallvector[x].push_back(y);
		}
		while(l--){
			cin >> x;
			play(indextofallvector, x);
		}

		cout << visited.count() << "\n";

	}
	return 0;
}
