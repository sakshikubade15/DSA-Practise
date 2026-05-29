// ## Edit Distance Problem (C++)

// This problem finds minimum operations required to convert one string into another.

// Allowed operations:
// - Insert
// - Delete
// - Replace

// ### Approach (Dynamic Programming)
// - If characters match:
//   no operation needed
// - Otherwise:
//   take minimum of:
//   insert, delete, replace

// ### Time Complexity
// O(n × m)

// ### Space Complexity
// O(n × m)

// ### Example
// Input:
// s1 = "horse"
// s2 = "ros"

// Output:
// 3
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to compute edit distance
    int editDistance(string s, string t) {

        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n + 1,
                               vector<int>(m + 1, 0));

        // Base cases
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                // Characters match
                if (s[i - 1] == t[j - 1]) {

                    dp[i][j] = dp[i - 1][j - 1];
                }

                // Operations
                else {

                    int insertOp  = dp[i][j - 1];
                    int deleteOp  = dp[i - 1][j];
                    int replaceOp = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min({insertOp,
                                        deleteOp,
                                        replaceOp});
                }
            }
        }

        return dp[n][m];
    }
};