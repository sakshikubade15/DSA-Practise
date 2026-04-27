// ## Rotate Array by One Position (C++)

// This program rotates an array by one position to the right.

// ### Approach
// - Store the last element
// - Shift all elements to the right
// - Place last element at index 0

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// [1, 2, 3, 4, 5]

// Output:
// [5, 1, 2, 3, 4]


#include <vector>
using namespace std;

class Solution {
public:
    // Function to rotate array by 1 position to the right
    void rotate(vector<int> &arr) {
        int n = arr.size();

        // Store last element
        int last = arr[n - 1];

        // Shift elements to the right
        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        // Place last element at first position
        arr[0] = last;
    }
};