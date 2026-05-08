// ## Triplet Sum in Array (C++)

// This program checks whether a triplet exists with a given target sum.

// ### Approach
// 1. Sort the array
// 2. Fix one element
// 3. Use two pointers for remaining part

// ### Time Complexity
// O(n²)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// arr = [1, 4, 45, 6, 10, 8]
// target = 22

// Output:
// true

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to check if triplet with target sum exists
    bool findTriplet(vector<int>& arr, int target) {
        int n = arr.size();

        // Step 1: Sort array
        sort(arr.begin(), arr.end());

        // Step 2: Fix one element
        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            // Step 3: Two pointer search
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == target) {
                    return true;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return false;
    }
};