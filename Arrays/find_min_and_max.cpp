// ## Find Minimum and Maximum in Array (C++)

// This program finds the minimum and maximum elements in an array using a single traversal.

// ### Approach
// - Initialize `mini` and `maxi` with the first element
// - Traverse the array from index 1
// - Update:
//   - `mini` if a smaller element is found
//   - `maxi` if a larger element is found

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Output Format
// Returns a vector containing:
// [min, max]

// ### Example
// Input:
// [3, 5, 1, 8, 2]

// Output:
// [1, 8]


#include <vector>
using namespace std;

class Solution {
public:
    // Function to find minimum and maximum element in an array
    vector<int> getMinMax(vector<int> &arr) {
        int mini = arr[0];
        int maxi = arr[0];

        // Traverse array to find min and max
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < mini) {
                mini = arr[i];
            }
            if (arr[i] > maxi) {
                maxi = arr[i];
            }
        }

        // Return result as {min, max}
        return {mini, maxi};
    }
};