//primepath at kattis. 0.02s.

#include <bits/stdc++.h>

#define MAXN 10000

using namespace std;

int calc_distance(int x, int y){
	int dist = 0;
	while(x > 0 && y > 0){
		if(x % 10 != y % 10) dist++;
		x /= 10; 
		y /= 10;
	}
	return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	bitset<MAXN> primes;
	primes[0] = primes[1] = true;
	//Prime sieve
	for(int i = 2; i < 100; i++){
		if(!primes[i]){
			int j = 2;
			while(i*j < MAXN){
				primes[i*j] = true;
				j++;
			}
		}
	}
	//collect interesting primes in range 1000 - 9999
	vector<int> usableprimes;
	for(int i = 1001; i < MAXN; i++){
		if(!primes[i]) usableprimes.push_back(i);
	}

	unordered_map<int, vector<int> > primetoprimes; //maps every prime to a vector containing all other primes which at at most one digit

	for(int i = 0; i < usableprimes.size(); i++){
		for(int j = 0; j < usableprimes.size(); j++){
			if(calc_distance(usableprimes[i], usableprimes[j]) == 1){
				primetoprimes[usableprimes[i]].push_back(usableprimes[j]);
			}
		}
	}

	int cases, start, end; cin >> cases;
	
	while(cases--){
		cin >> start >> end;
	
		priority_queue<pair<int, int> > pq;
		if(start == end){
			cout << "0\n";
			continue;
		}
		unordered_map<int, int> visited;

		pq.push(make_pair(0, start));
		while(!pq.empty()){
			int currentprime = pq.top().second;
			int currentcost = -pq.top().first;
			pq.pop();
			//cout << "currentcost = " << currentcost << "\n";
			if(visited[currentprime] != 0) continue;
			visited[currentprime] = currentcost;
			if(currentprime == end) break;
			for(int i = 0; i < primetoprimes[currentprime].size(); i++){
				pq.push(make_pair(-(currentcost + 1), primetoprimes[currentprime][i]));
				}
		}

		if(visited.find(end) == visited.end()) cout << "Impossible\n";
		else cout << visited[end] << "\n";

	}
	return 0;
}
