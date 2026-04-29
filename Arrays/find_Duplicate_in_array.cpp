// ## Find Duplicate Number (C++)

// This problem finds the duplicate number in an array.

// ### Approach 1: Sum Formula
// - Compute total sum
// - Subtract expected sum
// - Works only under strict conditions

// ### Approach 2: Floyd’s Cycle Detection (Recommended)
// - Treat array as linked list
// - Detect cycle using slow & fast pointers
// - Find entry point of cycle

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [1, 3, 4, 2, 2]

// Output:
// 2



#include <vector>
using namespace std;

class Solution {
public:
    // Function to find duplicate using Floyd's Cycle Detection
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Step 1: Detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Step 2: Find entry point (duplicate)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};