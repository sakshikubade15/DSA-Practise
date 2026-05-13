// ## Palindromic Array (C++)

// This problem checks whether all elements of an array are palindrome numbers.

// ### Approach
// - Reverse each number
// - Compare reversed number with original
// - If any number is not palindrome → return 0
// - Otherwise return 1

// ### Time Complexity
// O(n × digits)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [111, 222, 333, 444]

// Output:
// 1## Palindromic Array (C++)

// This problem checks whether all elements of an array are palindrome numbers.

// ### Approach
// - Reverse each number
// - Compare reversed number with original
// - If any number is not palindrome → return 0
// - Otherwise return 1

// ### Time Complexity
// O(n × digits)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [111, 222, 333, 444]

// Output:
// 1## Palindromic Array (C++)

// This problem checks whether all elements of an array are palindrome numbers.

// ### Approach
// - Reverse each number
// - Compare reversed number with original
// - If any number is not palindrome → return 0
// - Otherwise return 1

// ### Time Complexity
// O(n × digits)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [111, 222, 333, 444]

// Output:
// 1

#include <vector>
using namespace std;

class Solution {
public:

    // Function to check palindrome number
    bool isPalindrome(int num) {

        int original = num;
        int reverseNum = 0;

        while (num > 0) {
            int digit = num % 10;
            reverseNum = reverseNum * 10 + digit;
            num /= 10;
        }

        return original == reverseNum;
    }

    // Function to check if all array elements are palindrome
    int PalinArray(vector<int> &arr) {

        for (int num : arr) {
            if (!isPalindrome(num)) {
                return 0;
            }
        }

        return 1;
    }
};