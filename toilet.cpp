//Toilet seat at kattis. 0.00s
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int up_policy, down_policy, pref_policy = 0;
	down_policy = 0;
	up_policy = 0;
	//if toilet seat is not in the preferred position when the first person uses the bathroom, all policies are incremented.
	if(s[0] != s[1]){
		up_policy++; down_policy++; pref_policy++;
	}
	if(s[1] == 'U') down_policy++;
	if(s[1] == 'D') up_policy++;
	for(int i = 2; i < s.length(); i++){
		if(s[i] == 'U') down_policy += 2;
		else up_policy += 2;
		if(s[i] != s[i-1]) pref_policy++;
	}
	cout << up_policy << "\n" << down_policy << "\n" << pref_policy << "\n";
}
