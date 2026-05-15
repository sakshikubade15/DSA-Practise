// // ## Median of Two Sorted Arrays of Different Sizes (C++)

// // This problem finds the median of two sorted arrays using binary search.

// // ### Approach (Binary Search Partition)
// // - Partition both arrays into left and right halves
// // - Ensure:
// //   left1 <= right2
// //   left2 <= right1
// // - Compute median from partition values

// // ### Time Complexity
// // O(log(min(n1, n2)))

// // ### Space Complexity
// // O(1)

// // ### Example
// // Input:
// // a = [1, 3]
// // b = [2]

// // Output:
// // 2

// ## Median of Two Sorted Arrays of Different Sizes (C++)

// This problem finds the median of two sorted arrays using binary search.

// ### Approach (Binary Search Partition)
// - Partition both arrays into left and right halves
// - Ensure:
//   left1 <= right2
//   left2 <= right1
// - Compute median from partition values

// ### Time Complexity
// O(log(min(n1, n2)))

// ### Space Complexity
// O(1)

// ### Example
// Input:
// a = [1, 3]
// b = [2]

// Output:
// 2
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to find median of two sorted arrays
    double findMedian(vector<int>& a, vector<int>& b) {

        int n1 = a.size();
        int n2 = b.size();

        // Ensure first array is smaller
        if (n1 > n2) {
            return findMedian(b, a);
        }

        int low = 0;
        int high = n1;

        while (low <= high) {

            int cut1 = (low + high) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int left1  = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int left2  = (cut2 == 0) ? INT_MIN : b[cut2 - 1];

            int right1 = (cut1 == n1) ? INT_MAX : a[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : b[cut2];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                // Even total length
                if ((n1 + n2) % 2 == 0) {
                    return (max(left1, left2) +
                            min(right1, right2)) / 2.0;
                }

                // Odd total length
                else {
                    return max(left1, left2);
                }
            }

            // Move left
            else if (left1 > right2) {
                high = cut1 - 1;
            }

            // Move right
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};