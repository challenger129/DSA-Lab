#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void bubbleSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    srand((unsigned int)time(NULL));

    int sizes[] = {1000, 8000};
    int count = sizeof(sizes) / sizeof(sizes[0]);
    Solution s;

    cout << "Size InsertionSort BubbleSort\n";
    for (int idx = 0; idx < count; idx++) {
        int n = sizes[idx];
        vector<int> original(n);
        for (int i = 0; i < n; i++) {
            original[i] = rand();
        }

        vector<int> arr1(n);
        vector<int> arr2(n);
        for (int i = 0; i < n; i++) {
            arr1[i] = original[i];
            arr2[i] = original[i];
        }

        clock_t start1 = clock();
        s.insertionSort(&arr1[0], n);
        clock_t end1 = clock();

        clock_t start2 = clock();
        s.bubbleSort(&arr2[0], n);
        clock_t end2 = clock();

        double time1 = double(end1 - start1) / CLOCKS_PER_SEC;
        double time2 = double(end2 - start2) / CLOCKS_PER_SEC;

        cout << n << " " << time1 << " " << time2 << "\n";
    }

    return 0;
}
