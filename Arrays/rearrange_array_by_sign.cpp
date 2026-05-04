// ## Rearrange Array by Sign (C++)

// This problem rearranges an array such that positive and negative numbers alternate.

// ### Approach
// - Use two pointers:
//   - even index for positive numbers
//   - odd index for negative numbers
// - Traverse array and place elements accordingly

// ### Time Complexity
// O(n)

// ### Space Complexiy
// O(n)

// ### Example

// Input:
// [3, -2, 1, -5, 2, -4]

// Output:
// [3, -2, 1, -5, 2, -4]

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int posIndex = 0; // even index for positive
        int negIndex = 1; // odd index for negative

        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                result[posIndex] = nums[i];
                posIndex += 2;
            } else {
                result[negIndex] = nums[i];
                negIndex += 2;
            }
        }

        return result;
    }
};
