// ## Median of Two Sorted Arrays of Equal Size (C++)

// This problem finds the median of two sorted arrays having equal size.

// ### Approach
// - Use merge process of merge sort
// - Traverse arrays until middle elements are reached
// - Store last two elements
// - Return average of middle elements

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// a = [1, 2, 3, 6]
// b = [4, 6, 8, 10]

// Output:
// 5


#include <vector>
using namespace std;

class Solution {
public:
    // Function to find median of two sorted arrays
    double findMedian(vector<int>& a, vector<int>& b) {

        int n = a.size();

        int i = 0, j = 0;
        int count;

        int m1 = -1, m2 = -1;

        // Traverse until middle elements
        for (count = 0; count <= n; count++) {

            if (i == n) {
                m1 = m2;
                m2 = b[0];
                break;
            }

            else if (j == n) {
                m1 = m2;
                m2 = a[0];
                break;
            }

            // Pick smaller element
            if (a[i] <= b[j]) {
                m1 = m2;
                m2 = a[i];
                i++;
            }
            else {
                m1 = m2;
                m2 = b[j];
                j++;
            }
        }

        // Median of even size array
        return (m1 + m2) / 2.0;
    }
};