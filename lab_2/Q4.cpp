#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void reverse(int arr[], int start, int end){
        while(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    void rotatingAnArrayByKPositionsToTheRight(int arr[], int k,int n){
        k = k%n;
        reverse(arr,0,n-k-1);
        reverse(arr,n-k,n-1);
        reverse(arr,0,n-1);
        cout << "Array after " << k << " rotations: ";
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
    }
};
int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    Solution s;
    s.rotatingAnArrayByKPositionsToTheRight(arr,k,n);
    return 0;
}