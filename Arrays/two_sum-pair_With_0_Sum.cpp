// ## Find All Pairs with Sum = 0 (C++)

// This program finds all unique pairs in an array whose sum is zero.

// ### Approach
// 1. Sort the array
// 2. Use two pointers (left & right)
// 3. Move pointers based on sum:
//    - sum < 0 → move left
//    - sum > 0 → move right
//    - sum == 0 → store pair
// 4. Skip duplicates

// ### Time Complexity
// O(n log n)

// ### Space Complexity
// O(k)  (number of pairs)

// ### Example
// Input:
// [-1, 0, 1, 2, -1, -4]

// Output:
// [[-1, 1]]

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find all unique pairs with sum = 0
    vector<vector<int>> getPairs(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum < 0) {
                left++;
            }
            else if (sum > 0) {
                right--;
            }
            else {
                // Found a valid pair
                ans.push_back({arr[left], arr[right]});

                left++;
                right--;

                // Skip duplicates
                while (left < right && arr[left] == arr[left - 1]) {
                    left++;
                }
                while (left < right && arr[right] == arr[right + 1]) {
                    right--;
                }
            }
        }

        return ans;
    }
};