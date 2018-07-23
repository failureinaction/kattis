//Kastenlauf using unionfind.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int root[105];
typedef pair<int, int> pii;

int find(int x){
	if(root[x] == x) return x;
	return root[x] = find(root[x]);
}
void unite(int x, int y){
	root[find(x)] = find(y);
}

int main(){
	int t; cin >> t;
	while(t--){
		int n, x, y;
		cin >> n;
		vector<pii> locations;
		locations.resize(n + 2);
		for(int i = 0; i < n + 2; i++){
			root[i] = i;
			cin >> locations[i].first >> locations[i].second;
			for(int j = 0; j < i; j++){
				int dist = abs(locations[i].first - locations[j].first) + abs(locations[i].second - locations[j].second);
				if(dist <= 1000){
					unite(i, j);
				}
			}
		}
    //if home and Bergkirchweih are in the same set we're happy.
		if(find(0) == find(n + 1)){
			cout << "happy\n";
		}
		else{
			cout << "sad\n";
		}
	}
	return 0;
}
