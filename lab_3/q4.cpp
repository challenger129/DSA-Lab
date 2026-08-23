#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int equilibriumInd(int nums[], int n) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        int leftSum = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            total -= nums[i];
            if (leftSum == total) {
                cnt++;
            }
            leftSum += nums[i];
        }

        return cnt;
    }
};
int main(){
    int nums[] = {1, 3, 5, 2, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    Solution sol;
    int ans = sol.equilibriumInd(nums, n);
    cout << "The number of equilibrium indices is: " << ans << endl;
    return 0;
}