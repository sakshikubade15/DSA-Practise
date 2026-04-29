// ## Merge Two Sorted Arrays Without Extra Space (C++)

// This solution merges two sorted arrays without using extra space.

// ### Approach
// 1. Use two pointers:
//    - `i` from end of first array
//    - `j` from start of second array
// 2. Swap elements if they are in the wrong position
// 3. Sort both arrays individually

// ### Time Complexity
// O(n log n + m log m)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// a = [1, 5, 9, 10]
// b = [2, 3, 8]

// Output:
// a = [1, 2, 3, 5]
// b = [8, 9, 10]


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to merge two sorted arrays without extra space
    void merge(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        int i = n - 1;
        int j = 0;

        // Step 1: Swap elements if they are in wrong arrays
        while (i >= 0 && j < m) {
            if (a[i] > b[j]) {
                swap(a[i], b[j]);
                i--;
                j++;
            } else {
                break;
            }
        }

        // Step 2: Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};