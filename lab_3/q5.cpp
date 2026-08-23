#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalRainWaterTrapped(vector<int> &nums, int n) {
        if (n < 3) return 0;
        int lMax = 0, rMax = 0;
        int l = 0, r = n - 1;
        int total = 0;
        while(l < r) {
            if (nums[l] < nums[r]) {
                if (nums[l] >= lMax) {
                    lMax = nums[l];
                } else {
                    total += lMax - nums[l];
                }
                l++;
            } else {
                if (nums[r] >= rMax) {
                    rMax = nums[r];
                } else {
                    total += rMax - nums[r];
                }
                r--;
            }
        }
        return total;
    } 
};
int main(){
    int nums[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    vector<int> vec(nums, nums + n);
    Solution sol;
    int ans = sol.totalRainWaterTrapped(vec,n);
    cout << "The total rain water trapped is: " << ans << endl;
    return 0;
}