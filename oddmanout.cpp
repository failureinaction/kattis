//oddmanout at kattis. runtime 0.00s. 
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, g, current;
    cin >> n;
    for(int i = 1; i <= n; i++){
        unordered_map<int, int> guestlist;
        cin >> g;
        while(g--){
            cin >> current;
            guestlist[current]++;
        }
        for(auto it = guestlist.begin(); it != guestlist.end(); ++it){
            if(it->second == 1){
                cout << "Case #" << i << ": " << it->first << "\n";
                break; 
            }
        }
    }
    return 0;
}
