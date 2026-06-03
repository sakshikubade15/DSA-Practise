// ## KMP Algorithm (C++)

// KMP (Knuth-Morris-Pratt) is an efficient string matching algorithm.

// ### Approach
// 1. Build LPS array.
// 2. Match pattern with text.
// 3. On mismatch, use LPS to skip comparisons.

// ### Time Complexity
// O(n + m)

// ### Space Complexity
// O(m)

// ### Example

// Text:
// ABABDABACDABABCABAB

// Pattern:
// ABABCABAB

// Output:
// 10

#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    // Build LPS Array
    vector<int> computeLPS(string pattern) {

        int m = pattern.length();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {

            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {

                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    // KMP Search
    vector<int> search(string pattern, string text) {

        vector<int> ans;

        int n = text.length();
        int m = pattern.length();

        vector<int> lps = computeLPS(pattern);

        int i = 0; // text pointer
        int j = 0; // pattern pointer

        while (i < n) {

            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {

                ans.push_back(i - j);

                j = lps[j - 1];
            }

            else if (i < n && text[i] != pattern[j]) {

                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return ans;
    }
};