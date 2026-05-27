// ## Split Binary String into Substrings with Equal 0's and 1's (C++)

// This program finds maximum balanced binary substrings.

// A substring is balanced if:
// count(0) == count(1)

// ### Approach
// - Traverse string
// - Count zeros and ones
// - Whenever counts become equal:
//   one balanced substring found

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// "0100110101"

// Output:
// 4
#include <string>
using namespace std;

class Solution {
public:
    // Function to count balanced binary substrings
    int maxSubStr(string str) {

        int count0 = 0;
        int count1 = 0;

        int ans = 0;

        for (char ch : str) {

            // Count zeros
            if (ch == '0') {
                count0++;
            }

            // Count ones
            else {
                count1++;
            }

            // Balanced substring found
            if (count0 == count1) {
                ans++;
            }
        }

        // Entire string not balanced
        if (count0 != count1) {
            return -1;
        }

        return ans;
    }
};