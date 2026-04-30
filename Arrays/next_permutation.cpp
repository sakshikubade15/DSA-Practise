// ## Next Permutation (C++)

// This program finds the next lexicographically greater permutation of an array.

// ### Approach
// 1. Traverse from right and find first decreasing element (pivot)
// 2. If not found → reverse entire array
// 3. Find next greater element from right
// 4. Swap pivot with that element
// 5. Reverse the right portion

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [1, 2, 3]

// Output:
// [1, 3, 2]

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find next permutation
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Step 1: Find pivot (first decreasing element from right)
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot → reverse whole array
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find next greater element from right
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse right part
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};