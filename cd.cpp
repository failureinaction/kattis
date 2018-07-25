//simple implementation of cd-problem. 0.43s on kattis, which is quite slow. 

#include <iostream>
#include <bits/stdc++.h>
#define MAXN 10010000
using namespace std;

long long cdcol[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    int n, m;
    long long counter;
    long long x;
    while(cin >> n >> m && (n != 0 && m != 0)){
        counter = 0;
        memset(cdcol, 0, sizeof(cdcol));
        while(n--){
            cin >> x;
            cdcol[x] = 1;
        }
        while(m--){
            cin >> x;
            if(cdcol[x]) counter++;
        }
        cout << counter << "\n";
    }
    return 0;
}
