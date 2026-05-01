// ## Next Permutation (C++)

// This program finds the next lexicographically greater permutation of an array.

// ### Approach
// 1. Traverse from right and find first decreasing element (pivot)
// 2. If not found → reverse entire array
// 3. Find next greater element from right
// 4. Swap pivot with that element
// 5. Reverse the right portion

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [1, 2, 3]

// Output:
// [1, 3, 2]

#include <vector>
using namespace std;

class Solution {
public:
    // Merge function to count inversions
    long long merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left;
        int j = mid + 1;
        long long invCount = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);

                // Count inversions
                invCount += (mid - i + 1);
            }
        }

        // Remaining elements
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);

        // Copy back to original array
        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }

        return invCount;
    }

    // Merge sort function
    long long mergeSort(vector<int>& arr, int left, int right) {
        long long invCount = 0;

        if (left < right) {
            int mid = left + (right - left) / 2;

            invCount += mergeSort(arr, left, mid);
            invCount += mergeSort(arr, mid + 1, right);

            invCount += merge(arr, left, mid, right);
        }

        return invCount;
    }

    // Main function
    long long inversionCount(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};