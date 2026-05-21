// ## Check Whether a String is Valid Shuffle of Two Strings (C++)

// This program checks whether a string is a valid shuffle of two strings.

// ### Approach
// - Use three pointers:
//   - one for first string
//   - one for second string
//   - one for result string
// - Match characters while maintaining order

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// s1 = "abc"
// s2 = "def"
// result = "adbcef"

// Output:
// true

#include <string>
using namespace std;

class Solution {
public:
    // Function to check valid shuffle
    bool checkShuffle(string s1, string s2, string result) {

        int n1 = s1.length();
        int n2 = s2.length();

        // Length mismatch
        if (result.length() != n1 + n2) {
            return false;
        }

        int i = 0; // pointer for s1
        int j = 0; // pointer for s2
        int k = 0; // pointer for result

        while (k < result.length()) {

            // Match with s1
            if (i < n1 && s1[i] == result[k]) {
                i++;
            }

            // Match with s2
            else if (j < n2 && s2[j] == result[k]) {
                j++;
            }

            // Invalid character
            else {
                return false;
            }

            k++;
        }

        // All characters must be used
        return (i == n1 && j == n2);
    }
};