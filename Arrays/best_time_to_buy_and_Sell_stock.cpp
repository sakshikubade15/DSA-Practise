// ## Best Time to Buy and Sell Stock (C++)

// This problem finds the maximum profit from a single buy and sell transaction.

// ### Approach
// - Track minimum price so far
// - At each step, calculate profit = current price - min price
// - Keep updating maximum profit

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [7, 1, 5, 3, 6, 4]

// Output:
// 5

// Explanation:
// Buy at 1, sell at 6 → profit = 5

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find maximum profit from one transaction
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            // Track minimum price so far
            minPrice = min(minPrice, prices[i]);

            // Calculate profit if sold today
            int profit = prices[i] - minPrice;

            // Update maximum profit
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;  // ✅ correct
    }
};