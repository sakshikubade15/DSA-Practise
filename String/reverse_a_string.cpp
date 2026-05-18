// ## Reverse a String (C++)

// This program reverses a string using two pointers.

// ### Approach
// - Use two pointers:
//   - one from start
//   - one from end
// - Swap characters until pointers meet

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// "hello"

// Output:
// "olleh"

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to reverse a string
    string reverseString(string& s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};