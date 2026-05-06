// ## Stock Buy and Sell - Max 2 Transactions (C++)

// This problem finds the maximum profit with at most two transactions.

// ### Approach
// - Track 4 variables:
//   - buy1, sell1
//   - buy2, sell2
// - Update them while traversing prices

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [3,3,5,0,0,3,1,4]

// Output:
// 6

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find max profit with at most 2 transactions
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0;
        int buy2 = INT_MIN, sell2 = 0;

        for (int price : prices) {
            buy1 = max(buy1, -price);          // First buy
            sell1 = max(sell1, buy1 + price);  // First sell

            buy2 = max(buy2, sell1 - price);   // Second buy
            sell2 = max(sell2, buy2 + price);  // Second sell
        }

        return sell2;
    }
};