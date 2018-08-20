#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(false);
	int N, T;
	cin >> N >> T;
	int cash, time;
	vi customerslots(T + 1, 0);

	while(N--){
		cin >> cash >> time;
		for(int i = time; i >= 0; i--){
			if(customerslots[i] < cash) swap(customerslots[i], cash);
		}
	}
	int bankmoney = 0;
	for(auto cashmoney : customerslots) bankmoney += cashmoney;
	cout << bankmoney << "\n";
	return 0;
}
