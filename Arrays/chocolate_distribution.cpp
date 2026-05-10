// ## Chocolate Distribution Problem (C++)

// This problem distributes chocolate packets among students such that the

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to find minimum difference
    int findMinDiff(vector<int>& arr, int m) {

        int n = arr.size();

        // Edge cases
        if (m == 0 || n == 0) return 0;

        // Not enough packets
        if (m > n) return -1;

        // Step 1: Sort array
        sort(arr.begin(), arr.end());

        int mini = INT_MAX;

        // Step 2: Sliding window of size m
        for (int i = 0; i + m - 1 < n; i++) {

            int diff = arr[i + m - 1] - arr[i];

            mini = min(mini, diff);
        }

        return mini;
    }
};