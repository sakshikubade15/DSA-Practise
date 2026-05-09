// ## Trapping Rain Water (C++)

// This problem calculates how much rain water can be trapped between bars.

// ### Approach (Two Pointer)
// - Use two pointers:
//   - left pointer
//   - right pointer
// - Track:
//   - leftMax
//   - rightMax
// - Water trapped depends on smaller boundary

// ### Formula
// Water at index i:
// min(leftMax, rightMax) - height[i]

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [3, 0, 1, 0, 4, 0, 2]

// Output:
// 10
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to calculate trapped rain water
    int maxWater(vector<int> &arr) {
        int n = arr.size();

        int left = 0;
        int right = n - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while (left <= right) {

            // Process left side
            if (arr[left] <= arr[right]) {

                if (arr[left] >= leftMax) {
                    leftMax = arr[left];
                } else {
                    water += leftMax - arr[left];
                }

                left++;
            }

            // Process right side
            else {

                if (arr[right] >= rightMax) {
                    rightMax = arr[right];
                } else {
                    water += rightMax - arr[right];
                }

                right--;
            }
        }

        return water;
    }
};