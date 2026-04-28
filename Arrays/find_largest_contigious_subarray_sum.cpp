// ## Maximum Subarray Sum (Kadane’s Algorithm)

// This program finds the maximum sum of a contiguous subarray.

// ### Approach
// - Traverse the array
// - Add elements to current sum
// - If current sum becomes negative, reset it to 0
// - Track the maximum sum encountered

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [-2, 1, -3, 4, -1, 2, 1, -5, 4]

// Output:
// 6

// Explanation:
// Subarray [4, -1, 2, 1] has maximum sum = 6

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find maximum subarray sum
    int maxSubarraySum(vector<int> &arr) {
        int currentSum = 0;
        int maxSum = arr[0];

        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];

            // Update maximum sum
            maxSum = max(maxSum, currentSum);

            // Reset if sum becomes negative
            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};