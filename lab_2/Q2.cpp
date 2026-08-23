#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int toFindSecondLargest(int arr[], int n){
        int maxi = arr[0];
        int maxi2 = -1e5;
        for(int i = 1; i < n; i++){
            if(arr[i] > maxi){
                int temp = maxi;
                maxi = arr[i];
                maxi2 = temp;
            }
            else if(arr[i] == maxi){
                continue;
            }
            else if(arr[i] > maxi2){
                maxi2 = arr[i];
            }
        }
        if(maxi2 == -1e5)return -1;
        return maxi2;
    }
};
int main(){
    int arr[] = {-1,2,4,3,9,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution s;
    int result = s.toFindSecondLargest(arr, n);
    cout << result << '\n';
    return 0;
}