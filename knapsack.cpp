//Dynamic programming approach to knapsack at kattis. runs in 0.12s.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int find_max(int x, int y){
    if(x > y) return x;
    return y;
}

void dp(int c, int n, vector<pii> items){
    int w, v;
    int memo[n + 1][c + 1]; //memoization-matrix
    for(int i = 0; i <= c; i++){
        memo[0][i] = 0;
    }

    //First do dynamic programming
    //memo[i][c] = max(memo[i - 1][c], v_i + memo[i - 1][c - w_i])
    for(int i = 1; i <= n; i++){
        v = items[i - 1].first; //The value of the item
        w = items[i - 1].second; //The weight of the item
        for(int j = 0; j <= c; j++){
            if(j >= w){
                memo[i][j] = find_max(memo[i - 1][j], memo[i - 1][j - w] + v);
            }
            else{
                memo[i][j] = memo[i - 1][j];
            }
        }
    }
    vector<int> answers;
    int i = n;
    int j = c;

    //Then do backtracking to find which items were used to reach the optimal solution.
    while(memo[i][j] != 0){
        if(memo[i - 1][j] != memo[i][j]){
            answers.push_back(i - 1);
            j -= items[i - 1].second; //subtract the weight
        }
        i--;
    }

    cout << answers.size() << "\n";
    for(vector<int>::iterator it = answers.begin(); it != answers.end(); ++it){
        cout << *it << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    double C;
    int n;
    while(cin >> C >> n){
        int c = int(C);
        vector<pii> items(n + 1);
        for(int i = 0; i < n; i++){
            cin >> items[i].first >> items[i].second;
        }
        dp(c, n, items);
    }
    return 0;
}
