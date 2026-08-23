#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void allPossibleSubsets(vector<int> &nums, int k, vector<vector<int> > &ans, int ind, int n, int sum, vector<int> arr){
        if(ind >= n){
            if(sum == k){
                ans.push_back(arr);
            }
            return;
        }
        if(sum > k){
            return;
        }
        if(sum == k){
            ans.push_back(arr);
            return;
        }
        allPossibleSubsets(nums,k,ans,ind+1,n,sum,arr);
        arr.push_back(nums[ind]);
        allPossibleSubsets(nums,k,ans,ind+1,n,sum+nums[ind],arr);
        arr.pop_back();
    }
};
int main(){
        int arr[] = {1,2,3,4,5};
        vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
        int k = 5;
        vector<vector<int> > ans;
        Solution solution;
        solution.allPossibleSubsets(nums,k,ans,0,nums.size(),0,vector<int>());

        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Number of subsets possible with sum k : " << ans.size();
    }