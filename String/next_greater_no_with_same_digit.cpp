// ## Next Greater Number With Same Digits (C++)

// Find the next greater number that can be formed using the same set of digits.

// ### Approach
// 1. Find pivot from right.
// 2. Find smallest greater digit on right side.
// 3. Swap them.
// 4. Reverse remaining suffix.

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string nextGreater(string str) {

        int n = str.length();

        int pivot = -1;

        // Find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (str[i] < str[i + 1]) {
                pivot = i;
                break;
            }
        }

        // No next greater number exists
        if (pivot == -1) {
            return "-1";
        }

        // Find next greater digit
        for (int i = n - 1; i > pivot; i--) {
            if (str[i] > str[pivot]) {
                swap(str[i], str[pivot]);
                break;
            }
        }

        // Reverse remaining part
        reverse(str.begin() + pivot + 1, str.end());

        return str;
    }
};