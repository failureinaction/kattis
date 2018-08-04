//Ultraquicksort at kattis. runs in 0.10s.
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll counter = 0;

void mergesort(ll arr[], ll left, ll right){
    if(left < right){
        ll mid = left + (right - left)/2; //same as (left + right)/2 but deals with overflow
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);


        ll end_left = mid - left + 1;
        ll end_right = right - mid;

        ll left_half[end_left];
        ll right_half[end_right];
        for(ll i = 0; i < end_left; i++){
            left_half[i] = arr[left + i];
        }
        for(ll j = 0; j < end_right; j++){
            right_half[j] = arr[mid + j + 1];
        }
    
        ll i = 0;
        ll j = 0;
        ll pos = left;
        while(i < end_left && j < end_right){
            if(left_half[i] <= right_half[j]){
                arr[pos++] = left_half[i++];
            }else{
                //We only swap when the right half is less than the left half, otherwise it is already in ascending order.
                //The amount of elements we swap is the difference between the end of the left end of the interval
                //and i, which is the amount we have increased our left counter by in the left array.
                arr[pos++] = right_half[j++];
                counter += end_left - i;

            }
        }
        while(i < end_left){
            arr[pos++] = left_half[i++];
        }
        while(j < end_right){
            arr[pos++] = right_half[j++];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ll array[n];
    
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    mergesort(array, 0, n - 1);
    
    cout << counter << "\n";
    return 0;
}
