#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

unordered_map<string, string> root;
unordered_map<string, vector<string> > sets;

void unite(string x, string y){
	string xparent = root[x];
	string yparent = root[y];
	if(xparent == yparent) return;
	if(sets[xparent].size() >= sets[yparent].size()){
		for(vector<string>::iterator it = sets[yparent].begin(); it != sets[yparent].end(); ++it){
			sets[xparent].push_back(*it);
			root[*it] = xparent;
		}
		sets[yparent].clear();
		sets[yparent].push_back(yparent);
	}
	else{
		for(vector<string>::iterator it = sets[xparent].begin(); it != sets[xparent].end(); ++it){
			sets[yparent].push_back(*it);
			root[*it] = yparent;
		}
		sets[xparent].clear();
		sets[xparent].push_back(xparent);
	}
	return;
}

string find(string s){
	if(root[s] == s){
		return s;
	}
	root[s] = find(root[s]);
	return root[s];
}

void addToSet(string s){
	vector<string> set = {s};
	root[s] = s;
	sets[s] = set;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	string a, b;
	cin >> n;
	while(n--){
		cin >> m;
		while(m--){
			cin >> a >> b;
			if(root.find(a) == root.end()) addToSet(a);
			if(root.find(b) == root.end()) addToSet(b);
			unite(a, b);
			cout << sets[find(a)].size() << "\n";
		}
		root.clear();
		sets.clear();
	}
	return 0;
}
