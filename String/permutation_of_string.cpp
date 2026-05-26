// ## Print All Permutations of a String (C++)

// This program generates all permutations of a string using backtracking.

// ### Approach (Backtracking)
// - Fix one character at current position
// - Swap remaining characters recursively
// - Backtrack after recursion

// ### Time Complexity
// O(n × n!)

// ### Space Complexity
// O(n!)

// ### Example
// Input:
// "ABC"

// Output:
// ABC
// ACB
// BAC
// BCA
// CAB
// CBA

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Recursive function
    void solve(string str,
               int index,
               vector<string>& ans) {

        // Base case
        if (index == str.length()) {
            ans.push_back(str);
            return;
        }

        // Generate permutations
        for (int i = index; i < str.length(); i++) {

            swap(str[index], str[i]);

            solve(str, index + 1, ans);

            // Backtrack
            swap(str[index], str[i]);
        }
    }

    // Function to return all permutations
    vector<string> find_permutation(string S) {

        vector<string> ans;

        solve(S, 0, ans);

        // Sort permutations lexicographically
        sort(ans.begin(), ans.end());

        return ans;
    }
};