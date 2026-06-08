// ## Boyer-Moore Pattern Searching Algorithm (C++)

// Boyer-Moore searches for a pattern in a text using preprocessing.

// ### Key Idea
// - Compare from right to left.
// - On mismatch, skip multiple characters.
// - Uses Bad Character Heuristic.

// ### Time Complexity

// Best/Average:
// O(n/m)

// Worst:
// O(n × m)

// ### Space Complexity

// O(256)

// ### Example

// Text:
// ABAAABCD

// Pattern:
// ABC

// Output:
// 4

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:

    void badCharHeuristic(string pattern, vector<int>& badChar) {

        int m = pattern.length();

        for (int i = 0; i < 256; i++) {
            badChar[i] = -1;
        }

        for (int i = 0; i < m; i++) {
            badChar[pattern[i]] = i;
        }
    }

    vector<int> search(string text, string pattern) {

        vector<int> result;

        int n = text.length();
        int m = pattern.length();

        vector<int> badChar(256);

        badCharHeuristic(pattern, badChar);

        int shift = 0;

        while (shift <= n - m) {

            int j = m - 1;

            while (j >= 0 &&
                   pattern[j] == text[shift + j]) {
                j--;
            }

            // Pattern found
            if (j < 0) {

                result.push_back(shift);

                shift += (shift + m < n)
                         ? m - badChar[text[shift + m]]
                         : 1;
            }

            else {

                shift += max(
                    1,
                    j - badChar[text[shift + j]]
                );
            }
        }

        return result;
    }
};