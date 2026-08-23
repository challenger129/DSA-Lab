#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCircularSubArraySum(int nums[], int n){
        int maxSum = INT_MIN, currMax = 0;
        int minSum = INT_MAX, currMin = 0;
        int totalSum = 0;

        for(int i = 0; i < n; i++){
            currMax += nums[i];
            maxSum = max(maxSum, currMax);
            if(currMax < 0) currMax = 0;

            currMin += nums[i];
            minSum = min(minSum, currMin);
            if(currMin > 0) currMin = 0;

            totalSum += nums[i];
        }

        if(totalSum == minSum) return maxSum;
        return max(maxSum, totalSum - minSum);
        
    }
};
int main(){
    int nums[] = {1, 3, -2, 4, -1};
    int n = sizeof(nums) / sizeof(nums[0]);
    Solution sol;
    int ans = sol.maxCircularSubArraySum(nums, n);
    cout << "The maximum circular subarray sum is: " << ans << endl;
    return 0;
}