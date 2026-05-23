// ## Longest Palindromic Substring (C++)

// This problem finds the longest substring that is palindrome.

// ### Approach (Expand Around Center)
// - Every character can be center of palindrome
// - Expand in both directions
// - Check odd and even length palindromes
// - Track longest substring

// ### Time Complexity
// O(n²)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// "babad"

// Output:
// "bab"

#include <string>
using namespace std;

class Solution {
public:

    // Function to expand around center
    string expand(string s, int left, int right) {

        while (left >= 0 &&
               right < s.length() &&
               s[left] == s[right]) {

            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    // Function to find longest palindromic substring
    string longestPalindrome(string s) {

        string ans = "";

        for (int i = 0; i < s.length(); i++) {

            // Odd length palindrome
            string odd = expand(s, i, i);

            // Even length palindrome
            string even = expand(s, i, i + 1);

            // Update answer
            if (odd.length() > ans.length()) {
                ans = odd;
            }

            if (even.length() > ans.length()) {
                ans = even;
            }
        }

        return ans;
    }
};