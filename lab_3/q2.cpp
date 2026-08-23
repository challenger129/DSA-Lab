#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(int arr[], int n){
        if(n < 2)return 0;
        int mini = arr[0];
        int profit = 0;
        for(int i = 1; i < n; i++){
            if(mini > arr[i]){
                mini = arr[i];
            }
            profit = max(profit, arr[i] - mini);
        }
        return profit;
    }
};
int main() {
    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution sol;
    int ans = sol.maxProfit(arr, n);

    cout << "The maximum profit is: " << ans << endl;

    return 0;
}
