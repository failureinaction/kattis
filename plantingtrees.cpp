//plantingtrees at kattis. 0.01s
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	int time;
	vector<int> timeslots;
	for(int i = 0; i < N; i++){
		cin >> time;
		timeslots.push_back(time);
	}
	sort(timeslots.rbegin(), timeslots.rend());
	
	int totaldays = 1;
	int currentmax = 0;
	for(auto i : timeslots){
		totaldays++;
		currentmax--;
		if(currentmax < i) currentmax = i;
	}
	cout << totaldays + currentmax << "\n";
	return 0;
}
