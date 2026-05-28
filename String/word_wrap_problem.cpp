// ## Word Wrap Problem (C++)

// This problem arranges words into lines such that total penalty is minimized.

// Penalty:
// (extra spaces)^2

// Last line has no penalty.

// ### Approach (Dynamic Programming)
// - Try placing words in current line
// - Recursively solve remaining words
// - Use memoization to optimize

// ### Time Complexity
// O(n²)

// ### Space Complexity
// O(n)

// ### Example
// Input:
// nums = [3,2,2,5]
// k = 6

// Output:
// 10
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:

    // DP function
    int solve(int index,
              vector<int>& nums,
              int k,
              vector<int>& dp) {

        int n = nums.size();

        // Base case
        if (index == n) {
            return 0;
        }

        // Memoization
        if (dp[index] != -1) {
            return dp[index];
        }

        int ans = INT_MAX;

        int length = 0;

        // Try placing words in current line
        for (int i = index; i < n; i++) {

            length += nums[i];

            // Add space between words
            if (i > index) {
                length++;
            }

            // Exceeds line width
            if (length > k) {
                break;
            }

            int cost;

            // Last line → no cost
            if (i == n - 1) {
                cost = 0;
            }

            else {
                int extraSpace = k - length;

                cost = (extraSpace * extraSpace)
                       + solve(i + 1, nums, k, dp);
            }

            ans = min(ans, cost);
        }

        return dp[index] = ans;
    }

    // Main function
    int solveWordWrap(vector<int> nums, int k) {

        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(0, nums, k, dp);
    }
};