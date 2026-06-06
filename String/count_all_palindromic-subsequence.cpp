// ## Count All Palindromic Subsequences (C++)

// Given a string, count all palindromic subsequences.

// ### DP Relation

// If s[i] == s[j]:

// dp[i][j] =
// dp[i+1][j] +
// dp[i][j-1] + 1

// Else:

// dp[i][j] =
// dp[i+1][j] +
// dp[i][j-1] -
// dp[i+1][j-1]

// ### Time Complexity
// O(n²)

// ### Space Complexity
// O(n²)

// ### Example

// Input:
// "aaa"

// Output:
// 7


#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    long long countPS(string &s) {

        int n = s.length();

        vector<vector<long long>> dp(
            n, vector<long long>(n, 0)
        );

        // Single characters
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Length from 2 to n
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i <= n - len; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {

                    dp[i][j] =
                        dp[i + 1][j] +
                        dp[i][j - 1] + 1;
                }
                else {

                    dp[i][j] =
                        dp[i + 1][j] +
                        dp[i][j - 1] -
                        dp[i + 1][j - 1];
                }
            }
        }

        return dp[0][n - 1];
    }
}git