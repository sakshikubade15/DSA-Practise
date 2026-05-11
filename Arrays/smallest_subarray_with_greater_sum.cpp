// v## Smallest Subarray with Sum Greater Than X (C++)

// This problem finds the minimum length subarray whose sum is greater than x.

// ### Approach (Sliding Window)
// - Expand window by adding elements
// - Shrink window while sum > x
// - Track minimum window length

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// arr = [1, 4, 45, 6, 10, 19]
// x = 51

// Output:
// 3

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to find smallest subarray length
    int smallestSubWithSum(int x, vector<int>& arr) {

        int n = arr.size();

        int minLength = INT_MAX;
        int sum = 0;
        int left = 0;

        // Expand window
        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Shrink window while sum > x
            while (sum > x) {

                minLength = min(minLength, right - left + 1);

                sum -= arr[left];
                left++;
            }
        }

        // If no valid subarray found
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};