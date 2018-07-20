//Using stl
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int casecounter = 1;
	int n, m;
	long int current, p;
	vector<long int> set, queries, closest;
	while(cin >> n){
		cout << "Case " << casecounter << ":\n";
		casecounter++;
		while(n--){
			cin >> p;
			set.push_back(p);
		}
		cin >> m;
		while(m--){
			cin >> p;
			queries.push_back(p);
		}
		for(int i = 0; i < queries.size(); i++){
			closest.push_back(1000000000);
		}
		for(int i = 0; i < set.size(); i++){
			for(int j = i + 1; j < set.size(); j++){
				current = set[i] + set[j];
				for(int k = 0; k < queries.size(); k++){
					if(abs(current - queries[k]) < abs(queries[k] - closest[k])){
						closest[k] = current;
					}
				}
			}
		}
		for(int i = 0; i < queries.size(); i++){
			cout << "Closest sum to " << queries[i] << " is " << closest[i] << ".\n";
		}
		set.clear();
		queries.clear();
		closest.clear();
	}
	return 0;
}
