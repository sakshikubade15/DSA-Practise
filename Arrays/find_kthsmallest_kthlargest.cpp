// ## K-th Smallest Element in Array (C++)

// This program finds the k-th smallest element in an array.

// ### Approach
// - Sort the array in ascending order
// - Return the element at index (k-1)

// ### Time Complexity
// O(n log n)  (due to sorting)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// arr = [7, 10, 4, 3, 20, 15], k = 3

// Output:
// 7


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find the k-th smallest element in the array
    int kthSmallest(vector<int> &arr, int k) {
        // Sort the array
        int n=arr.size();
        sort(arr.begin(), arr.end());

        // Return k-th smallest (1-based index)
        return {arr[k - 1]};


    }
};

// similarly for kth largest-return {arr[n-k]}