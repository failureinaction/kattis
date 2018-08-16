//happy happy prime prime at kattis. 0.01s. 
#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x){
	if(x < 2) return false;
	for(int i = 2; i <= sqrt(x); i++){
		if(x % i == 0) return false;
	}
	return true;
}

bool is_happy(int x){
	int sum;
	unordered_map<int, int> visited;
	while(1){
		sum = 0;
		while(x > 0){
			sum += pow(x % 10, 2);
			x /= 10;
		}
		if(sum == 1) return true;
		if(visited[sum]) return false;
		visited[sum] = 1;
		x = sum;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	int case_index, m;
	while(T--){
		cin >> case_index >> m;
		cout << case_index << " "<< m;
		if(is_prime(m) && is_happy(m)) cout << " YES\n";
		else cout << " NO\n"; 

	}
	return 0;
}
