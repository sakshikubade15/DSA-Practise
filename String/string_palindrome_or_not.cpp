// ## Check Whether String is Palindrome (C++)

// This program checks whether a string is palindrome or not.

// ### Approach
// - Use two pointers:
//   - one from beginning
//   - one from end
// - Compare characters
// - If mismatch occurs → not palindrome

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// "madam"

// Output:
// true

#include <string>
using namespace std;

class Solution {
public:
    // Function to check if string is palindrome
    bool isPalindrome(string& s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Characters do not match
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};