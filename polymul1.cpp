//polymul1 at kattis. runs in 0.01s
#include <bits/stdc++.h>

using namespace std;

#define MAXN 256

int poly1[MAXN];
int poly2[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int T, deg1, deg2;
	cin >> T;
	while(T--){
		int maxdegree = 0;
		cin >> deg1;
		for(int i = 0; i < deg1 + 1; i++){
			cin >> poly1[i];
		}
		cin >> deg2;
		for(int i = 0; i < deg2 + 1; i++){
			cin >> poly2[i];
		}
		vector<int> results((deg1+1) * (deg2+1));
		for(int i = 0; i < deg1 + 1; i++){
			for(int j = 0; j < deg2+1; j++){
				results[i + j] += poly1[i] * poly2[j];
				if(results[i + j] != 0 && i + j > maxdegree) maxdegree = i + j;
			}
		}
		cout << maxdegree << "\n";
		for(int i = 0; i < maxdegree + 1; i++){
			cout << results[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
