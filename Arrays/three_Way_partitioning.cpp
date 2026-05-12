// ## Three Way Partitioning (C++)

// This problem rearranges the array into three parts:
// - elements less than a
// - elements in range [a, b]
// - elements greater than b

// ### Approach (Dutch National Flag Algorithm)
// - Use three pointers:
//   - low
//   - mid
//   - high
// - Partition array in one traversal

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// arr = [1, 2, 3, 3, 4]
// a = 1
// b = 2

// Output:
// [1, 2, 3, 3, 4]

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to partition array around range [a, b]
    void threeWayPartition(vector<int>& arr, int a, int b) {

        int low = 0;
        int mid = 0;
        int high = arr.size() - 1;

        while (mid <= high) {

            // Element smaller than a
            if (arr[mid] < a) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }

            // Element in range [a, b]
            else if (arr[mid] >= a && arr[mid] <= b) {
                mid++;
            }

            // Element greater than b
            else {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};