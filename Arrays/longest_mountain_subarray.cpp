// ## Longest Mountain Subarray (C++)

// A mountain subarray is strictly increasing and then strictly decreasing.

// ### Approach
// - Traverse array
// - Treat every valid peak
// - Expand left and right
// - Calculate mountain length

// ### Time Complexity
// O(n²)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [2, 1, 4, 7, 3, 2, 5]

// Output:
// 
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find length of longest mountain subarray
    int longestMountain(vector<int>& arr) {

        int n = arr.size();

        if (n < 3) return 0;

        int longest = 0;

        for (int i = 1; i < n - 1; i++) {

            // Check peak
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {

                int left = i;
                int right = i;

                // Expand left
                while (left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }

                // Expand right
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }

                // Update maximum length
                longest = max(longest, right - left + 1);
            }
        }

        return longest;
    }
};
