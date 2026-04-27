// ## Move Negative Elements to Left (C++)

// This program rearranges the array so that all negative numbers appear on the left side and positive numbers on the right.

// ### Approach
// - Use two pointers:
//   - left from beginning
//   - right from end
// - Swap misplaced elements

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [1, -2, 3, -4, -1, 4]

// Output:
// [-1, -2, -4, 3, 1, 4] (order may vary)

#include <vector>
using namespace std;

class Solution {
public:
    // Function to move all negative elements to the left side
    void moveNegatives(vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            if (arr[left] < 0) {
                left++; // already correct
            }
            else if (arr[right] >= 0) {
                right--; // already correct
            }
            else {
                // swap positive (left) with negative (right)
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};