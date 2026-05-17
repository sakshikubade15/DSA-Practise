// ## Transform and Sort Array (C++)

// This problem transforms array elements:
// - Negative numbers → square
// - Positive numbers → cube

// Then sorts the array.

// ### Approach
// 1. Traverse array
// 2. Transform elements
// 3. Sort final array

// ### Time Complexity
// O(n log n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [-3, 1, 2]

// Output:
// [1, 8, 9]
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to transform and sort array
    vector<int> sortArray(vector<int>& arr) {

        int n = arr.size();

        // Transform elements
        for (int i = 0; i < n; i++) {

            // Negative → square
            if (arr[i] < 0) {
                arr[i] = arr[i] * arr[i];
            }

            // Positive or zero → cube
            else {
                arr[i] = arr[i] * arr[i] * arr[i];
            }
        }

        // Sort transformed array
        sort(arr.begin(), arr.end());

        return arr;
    }
};