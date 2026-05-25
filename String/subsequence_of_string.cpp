// ## Print All Subsequences of a String (C++)

// This program generates all subsequences of a string using recursion.

// ### Approach (Recursion)
// For every character:
// - include it
// - exclude it

// Generate all possible combinations recursively.

// ### Time Complexity
// O(2ⁿ)

// ### Space Complexity
// O(2ⁿ)

// ### Example
// Input:
// "ab"

// Output:
// "", "a", "b", "ab"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Recursive function
    void solve(string str,
               int index,
               string output,
               vector<string>& ans) {

        // Base case
        if (index == str.length()) {
            ans.push_back(output);
            return;
        }

        // Exclude current character
        solve(str, index + 1, output, ans);

        // Include current character
        output.push_back(str[index]);
        solve(str, index + 1, output, ans);
    }

    // Function to generate all subsequences
    vector<string> allSubsequences(string str) {

        vector<string> ans;
        string output = "";

        solve(str, 0, output, ans);

        return ans;
    }
};