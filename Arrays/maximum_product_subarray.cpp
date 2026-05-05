// ## Maximum Product Subarray (C++)

// This problem finds the maximum product of a contiguous subarray.

// ### Approach (Prefix + Suffix)
// - Traverse from left → compute prefix product
// - Traverse from right → compute suffix product
// - Reset product when it becomes 0
// - Track maximum value

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [2, 3, -2, 4]

// Output:
// 6

// Explanation:
// Subarray [2, 3] gives max product = 6

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int ans = INT_MIN;

        int prefix = 1;
        int suffix = 1;

        for (int i = 0; i < n; i++) {
            // Reset when product becomes 0
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            prefix *= arr[i];
            suffix *= arr[n - i - 1];

            ans = max(ans, max(prefix, suffix));
        }

        return ans;
    }
};