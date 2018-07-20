//Using standard arrays of ints instead of stl.

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long int queries[26];
	long int set[1001];
	long int closest[1001];
	int casecounter = 1;
	int n, m, p;
	while(cin >> n){
		cout << "Case " << casecounter << ":\n";
		casecounter++;
		for(int i = 0; i < n; i++){
			cin >> p;
			set[i] = p;
		}
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> p;
			closest[i] = 1000000000;
			queries[i] = p;
		}
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				for(int k = 0; k < m; k++){
					if(abs(set[i] + set[j] - queries[k]) < abs(closest[k] - queries[k])){
						closest[k] = set[i] + set[j];
					}
				}
			}
		}
		for(int i = 0; i < m; i++){
			cout << "Closest sum to " << queries[i] << " is " << closest[i] << ".\n";
		}
	}

	return 0;
}
