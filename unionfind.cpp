//unionfind at kattis. Runs in 0.27s.
#include <bits/stdc++.h>

using namespace std;

int root[1000005];

int find(int x){
    if(root[x] == x) return x;
    root[x] = find(root[x]);
    return root[x];
}

void unite(int x, int y){
    root[find(x)] = find(y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n + 1; i++){
        root[i] = i;
    }
    string op;
    int x, y;
    while(q--){
        cin >> op >> x >> y;
        if(op == "="){
            unite(x, y);
        }
        else if(op == "?"){
            if(find(x) == find(y)){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
        }
    }
    return 0;
}
