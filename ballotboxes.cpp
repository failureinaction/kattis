//ballotboxes at kattis. 0.08s.
#include <bits/stdc++.h>

using namespace std;
#define MAXN 5000000
int populations[MAXN];

int count_boxes(int key, int n){
    int boxes = 0;
    for(int i = 0; i < n; i++){
        boxes += (populations[i] + key - 1) / key ;
    }
    return boxes;
}
int main(){
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    int n, b, result, maximum;
    while(cin >> n >> b && (n != -1 && b != -1)){
        maximum = 0;
        for(int i = 0; i < n; i++){
            cin >> populations[i];
            if(populations[i] > maximum) maximum = populations[i];
        }
        int low = 1;
        int high = maximum;
        int mid;
        while(high - low > 1){
            mid = (low + high) / 2;
            if(count_boxes(mid, n) <= b) high = mid;
            else low = mid;
        }
        cout << high << "\n";
        //result = binsearch(n, b);
    }
    return 0;
}
