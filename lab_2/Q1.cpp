#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int arr[10000];
    int currSize;
    Solution() : currSize(0) {}
    void reverse(int arr[], int start, int end){
        while(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    void insert(int arr[], int ind, int val){
        reverse(arr, ind, currSize - 1);
        arr[currSize] = val;
        currSize++;
        reverse(arr, ind, currSize - 1);
    }
    void Delete(int arr[], int ind){
        for(int i = ind; i < currSize - 1; i++){
            arr[i] = arr[i + 1];
        }
        currSize--;
    }
};
int main(){
    Solution s;
    s.insert(s.arr, 0, 1);
    s.insert(s.arr, 1, 2);
    s.insert(s.arr, 2, 3);
    s.insert(s.arr, 3, 4);
    s.insert(s.arr, 4, 5);
    cout << "Array after insertions: ";
    for(int i = 0; i < s.currSize; i++){
        cout << s.arr[i] << " ";
    }
    cout << endl;

    s.Delete(s.arr, 2);
    cout << "Array after deletion at index 2: ";
    for(int i = 0; i < s.currSize; i++){
        cout << s.arr[i] << " ";
    }
    cout << endl;

    return 0;
}