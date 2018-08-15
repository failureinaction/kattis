//Password at kattis. 0.00s.
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string pword;
	float prob;
	float total = 0;
	vector<float> probabilities(n);
	for(int i = 0; i < n; i++){
		cin >> pword >> probabilities[i];
	}
	sort(probabilities.rbegin(), probabilities.rend());
	for(int i = 0; i < probabilities.size(); i++){
		total += (i+1)*probabilities[i];
	}
	cout << fixed;
	cout.precision(5);
	cout << total << "\n";
	return 0;
}
