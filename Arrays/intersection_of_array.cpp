// ## Intersection of Two Arrays (C++)

// This program finds the intersection of two arrays (only common unique elements).

// ### Approach
// 1. Sort both arrays
// 2. Use two pointers to traverse
// 3. Compare elements:
//    - Move pointer of smaller element
//    - If equal, add to result (avoid duplicates)

// ### Time Complexity
// O(n log n + m log m)

// ### Space Complexity
// O(min(n, m))

// ### Example
// Input:
// a = [1, 2, 2, 3, 4]
// b = [2, 2, 3, 5]

// Output:
// [2, 3]

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find intersection of two arrays (unique elements)
    vector<int> intersection(vector<int>& a, vector<int>& b) {

        // Step 1: Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0;
        int n = a.size(), m = b.size();

        vector<int> result;

        // Step 2: Traverse both arrays
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                i++;
            }
            else if (a[i] > b[j]) {
                j++;
            }
            else {
                // Avoid duplicates
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
                j++;
            }
        }

        return result;
    }
};