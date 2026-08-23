#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int randomIndex(int left, int right){
        int len = right - left + 1;
        return (rand() % len) + left;
    }
    int partitionInd(int nums[], int pi, int left, int right){
        int pivot = nums[pi];
        swap(nums[left],nums[pi]);
        int ind = left + 1;
        for(int i = left + 1;i <= right;i++){
            if(nums[i]>pivot){
                swap(nums[ind],nums[i]);
                ind++;
            }
        }
        swap(nums[left],nums[ind-1]);
        return ind;
    }
public:
    int nThLargest(int nums[], int size, int n) {
        if(n > size)return -1;
        int left = 0;
        int right = size - 1;
        while(true){
            int pi = randomIndex(left,right);
            pi = partitionInd(nums,pi,left,right);
            if(pi == n)return nums[pi-1];
            else if(pi > n) right = pi-2;
            else{
                left = pi;
            }
        }
    }
};
int main() {
    int nums[] = {-5, 4, 1, 2, -3};
    int size = sizeof(nums) / sizeof(nums[0]);
    int n = 3;
    Solution sol;
    int ans = sol.nThLargest(nums, size, n);

    cout << "The nth largest element in the array is: " << ans << endl;

    return 0;
}