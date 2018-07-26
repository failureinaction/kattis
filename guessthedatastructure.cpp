//guessthedatastructue @ kattis. 0.01s.

#include <bits/stdc++.h>
#include <queue>
#include <stack>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	
	int n, x, y, counter;
	bool is_stack, is_queue, is_pq;
	
	while(cin >> n){
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		is_stack = true; is_queue = true; is_pq = true;
		counter = 3;
		while(n--){
			cin >> x >> y;
			if(x == 1){
				q.push(y);
				s.push(y);
				pq.push(y);
			}
			else if(x == 2){
				if(q.empty() == true){
					counter = 0;
					continue;
				}
				if(q.front() != y && is_queue){
					is_queue = false;
					counter--;
				}
				if(s.top() != y && is_stack){
					is_stack = false;
					counter--;
				}
				if(pq.top() != y && is_pq){
					is_pq = false;
					counter--;
				}
				q.pop(); s.pop(); pq.pop();
			}
		}
		if(is_stack && counter == 1) cout << "stack\n";
		else if(is_queue == true && counter == 1) cout << "queue\n";
		else if(is_pq == true && counter == 1) cout << "priority queue\n";
		else if(counter > 1) cout << "not sure\n";
		else if(counter < 1) cout << "impossible\n";
	}
	return 0;
}
