// ## Word Break Problem (C++)

// Given a string and a dictionary of valid words,
// determine whether the string can be segmented
// into dictionary words.

// ### Approach
// - Use Dynamic Programming
// - dp[i] indicates whether substring [0...i-1]
//   can be formed using dictionary words

// ### Time Complexity
// O(n²)

// ### Space Complexity
// O(n)

// ### Example

// Input:
// s = "ilike"

// Dictionary:
// ["i", "like"]

// Output:
// 1

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int wordBreak(string s, vector<string>& dictionary) {

        unordered_set<string> dict(dictionary.begin(),
                                   dictionary.end());

        int n = s.length();

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j < i; j++) {

                if (dp[j] &&
                    dict.find(s.substr(j, i - j)) != dict.end()) {

                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};