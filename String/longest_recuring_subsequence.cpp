// ## Longest Recurring Subsequence (C++)

// This problem finds the length of the longest subsequence that appears more than once in a string.

// ### Approach (LCS Variation)
// - Apply Longest Common Subsequence on same string
// - Ignore same indices using:
//   i != j

// ### Time Complexity
// O(n²)

// ### Space Complexity
// O(n²)

// ### Example
// Input:
// "AABEBCDD"

// Output:
// 3

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find length of longest repeating subsequence
    int LongestRepeatingSubsequence(string str) {

        int n = str.length();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // LCS logic with i != j
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= n; j++) {

                // Characters match but index should be different
                if (str[i - 1] == str[j - 1] && i != j) {

                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                else {
                    dp[i][j] = max(dp[i - 1][j],
                                   dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }
};