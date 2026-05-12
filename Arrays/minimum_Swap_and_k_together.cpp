// ## Minimum Swaps and K Together (C++)

// This problem finds the minimum swaps required to bring all elements less than or equal to k together.

// ### Approach (Sliding Window)
// 1. Count elements <= k
// 2. Use this count as window size
// 3. Count bad elements (> k) in each window
// 4. Minimum bad count = answer

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// arr = [2, 1, 5, 6, 3]
// k = 3

// Output:
// 1


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find minimum swaps required
    int minSwap(vector<int>& arr, int k) {

        int n = arr.size();

        // Count good elements (<= k)
        int good = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) {
                good++;
            }
        }

        // Count bad elements in first window
        int bad = 0;
        for (int i = 0; i < good; i++) {
            if (arr[i] > k) {
                bad++;
            }
        }

        int ans = bad;

        // Sliding window
        int left = 0;
        int right = good;

        while (right < n) {

            // Remove outgoing element
            if (arr[left] > k) {
                bad--;
            }

            // Add incoming element
            if (arr[right] > k) {
                bad++;
            }

            // Update answer
            ans = min(ans, bad);

            left++;
            right++;
        }

        return ans;
    }
};