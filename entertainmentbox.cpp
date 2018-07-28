//kattis entertainmentbox. Using greedy algorithm. Runs in 0.05s. 
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

bool paircmp(pii a, pii b){
	return a.second < b.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<pii> programme (n);
	for(int i = 0; i < n; i++){
		cin >> programme[i].first >> programme[i].second;
	}
	sort(programme.begin(), programme.end(), paircmp);

	multiset<int> endtime;

	int counter = 0;

	for(auto it = programme.begin(); it != programme.end(); ++it){
		multiset<int>::iterator iter = endtime.upper_bound((*it).first); //Returns an iterator pointing to the first element in the container which is considered to go after val.
		if(iter != endtime.begin()){ //multiset sorts from smallest to greatest, thus if iter == endtime.begin() it means that the current value.first is lower than the nearest endtime.
			--iter; //Because iter now points to the first value AFTER where (*it).first goes, we want to remove the element ahead of it.
			endtime.erase(iter);
			endtime.insert((*it).second);
			counter++;
		}
		else if(k){
			counter++;
			k--;
			endtime.insert((*it).second);
		}
	}
	cout << counter << "\n";

	return 0;
}
