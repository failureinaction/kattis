//primesieve at kattis. 0.70s.
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q, x;
	cin >> n >> q;
	vector<bool> primes(n + 1, true);
	primes[0] = primes[1] = false;
	int total = 0;
	int nsqrt = sqrt(n);
	
	//prime sieve
	for(int i = 2; i <= nsqrt; i++){
		if(primes[i]){
			int j = 2;
			total++;
			while(j*i <= n){
				primes[j*i] = false;
				j++;
			}
		}
	}
	//count remaining primes
	for(int i = nsqrt + 1; i <= n; i++){
		if(primes[i]) total++;
	}

	cout << total << "\n";
	
	//handle the queries
	while(q--){
		cin >> x;
		cout << primes[x] << "\n";
	}
	return 0;
}
