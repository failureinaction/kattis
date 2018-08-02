//longest increasing subsequence problem at kattis. Runs in 0.06s. 
//References: Algorithm and understanding from https://www.geeksforgeeks.org/construction-of-longest-monotonically-increasing-subsequence-n-log-n/


#include <bits/stdc++.h>

using namespace std;

int find_ceiling(vector<int>& arr, vector<int>& tail, int low, int high, int key){
    while(low < high){
        int mid = (low + high)/2;
        if(arr[tail[mid]] >= key){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return high;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    while(cin >> n){
        vector<int> seq(n);
        vector<int> tailIndex(n);
        vector<int> prevIndex(n, -1);
        cin >> seq[0];
        
        int length = 1;
        for(int i = 1; i < n; i++){
            cin >> seq[i];
            if(seq[i] < seq[tailIndex[0]]){
                tailIndex[0] = i;
            }
            else if(seq[i] > seq[tailIndex[length - 1]]){
                prevIndex[i] = tailIndex[length - 1];
                tailIndex[length++] = i;
            }
            else{
                int ceilIndex = find_ceiling(seq, tailIndex, 0, length - 1, seq[i]);
                prevIndex[i] = tailIndex[ceilIndex - 1];
                tailIndex[ceilIndex] = i;
            }
        }
        
        cout << length << "\n";
        vector<int> answers;
        for(int i = tailIndex[length - 1]; i >= 0; i = prevIndex[i]){
            answers.push_back(i);
        }
        for(int i = length - 1; i >= 0; i--){
            cout << answers[i] << " ";
        }
        cout << "\n";
    }
}
