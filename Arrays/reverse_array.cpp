//  Reverse Array (C++)

// This program reverses an array in-place using the two-pointer approach.

// Approach
// - Initialize two pointers:
//   - `start` at the beginning
//   - `end` at the last index
// - Swap elements at `start` and `end`
// - Move `start` forward and `end` backward
// - Continue until both pointers meet

// Time Complexity
// O(n)

//  Space Complexity
// O(1)

// Key Concept
// Two-pointer technique

#include <vector>
using namespace std;

class Solution {
public:
    // Function to reverse the given array in-place
    void reverseArray(vector<int> &arr) {
        int start = 0;
        int end = arr.size() - 1;

        // Swap elements from both ends moving towards center
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
};