#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void changingOrderOnTheBasisOfSigns(vector<int> &nums){
        int n = nums.size();
        if(n <= 1)return;
        int posInd = 0;
        int negInd = 1;
        while(posInd < n && negInd < n){
            while(posInd < n && nums[posInd] >= 0) posInd += 2;
            while(negInd < n && nums[negInd] <= 0) negInd += 2;
            if(posInd < n && negInd < n){
                swap(nums[posInd], nums[negInd]);
            }
        }
    }
};
int main(){
        int arr[] = {1,2,-1,-4,3,-3,3,-4};
        vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
        Solution solution;
        solution.changingOrderOnTheBasisOfSigns(nums);

        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
    }
    