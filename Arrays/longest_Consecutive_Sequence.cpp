// ## Longest Consecutive Sequence (C++)

// This problem finds the length of the longest sequence of consecutive integers.

// ### Approach (Hash Set)
// - Insert all elements into a set
// - For each element:
//   - Check if it is the start of a sequence (no previous element)
//   - Count consecutive numbers
// - Track maximum length

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(n)

// ### Example
// Input:
// [100, 4, 200, 1, 3, 2]

// Output:
// 4

// Explanation:
// Sequence: [1, 2, 3, 4]

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to return length of longest consecutive subsequence
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        unordered_set<int> st(arr.begin(), arr.end());

        int longest = 1;

        for (auto it : st) {
            // Check if it is the start of a sequence
            if (st.find(it - 1) == st.end()) {
                int count = 1;
                int x = it;

                // Count consecutive elements
                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};