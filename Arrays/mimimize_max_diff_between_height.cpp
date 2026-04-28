// ## Minimize the Maximum Difference Between Heights (C++)

// This problem minimizes the difference between the tallest and shortest tower after increasing or decreasing each element by k.

// ### Approach
// 1. Sort the array
// 2. Initialize result as max - min
// 3. Modify smallest and largest
// 4. Traverse and update min/max dynamically

// ### Time Complexity
// O(n log n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// arr = [1, 5, 8, 10], k = 2

// Output:
// 5

// Explanation:
// Modified array → [3, 3, 6, 8]
// Difference = 8 - 3 = 5

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to minimize the difference between heights
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();

        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        // Initial difference
        int ans = arr[n - 1] - arr[0];

        // Smallest and largest after modification
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        // Step 2: Traverse and update answer
        for (int i = 1; i < n; i++) {
            // Skip if height becomes negative
            if (arr[i] - k < 0) continue;

            int mini = min(smallest, arr[i] - k);
            int maxi = max(largest, arr[i - 1] + k);

            ans = min(ans, maxi - mini);
        }

        return ans;
    }
};