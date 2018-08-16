//primesieve at kattis. 0.61s. This time using bitset instead of a vector.
#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000002
bitset<MAXN> primes;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
	int n, q, x, j;
	cin >> n >> q;

	primes.set(0); primes.set(1);
	int nsqrt = sqrt(n);
	for(int i = 2; i <= nsqrt; i++){
		if(!primes[i]){
			j = 2;
			while(j*i <= n){
				primes.set(j*i);
				j++;
			}
		}
	}
	int total = n - primes.count() + 1;
	cout << total << "\n";
	while(q--){
	    cin >> x;
	    x = primes[x] ? 0 : 1;
	    cout << x << "\n";
	}	
	return 0;
}
