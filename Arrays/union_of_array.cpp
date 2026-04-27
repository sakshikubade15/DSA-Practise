// ## Union of Two Arrays (C++)

// This program finds the union of two arrays (unique elements only).

// ### Approach
// 1. Sort both arrays
// 2. Use two pointers to traverse both arrays
// 3. Add elements in sorted order while avoiding duplicates

// ### Time Complexity
// O(n log n + m log m)

// ### Space Complexity
// O(n + m)

// ### Example
// Input:
// a = [1, 2, 2, 3, 4]
// b = [2, 3, 5]

// Output:
// [1, 2, 3, 4, 5]

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find union of two arrays (unique elements)
    vector<int> findUnion(vector<int>& a, vector<int>& b) {

        // Step 1: Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0;
        int n = a.size(), m = b.size();

        vector<int> result;

        // Step 2: Merge both arrays while avoiding duplicates
        while (i < n && j < m) {
            if (a[i] <= b[j]) {
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
            } else {
                if (result.empty() || result.back() != b[j]) {
                    result.push_back(b[j]);
                }
                j++;
            }
        }

        // Step 3: Add remaining elements from array a
        while (i < n) {
            if (result.empty() || result.back() != a[i]) {
                result.push_back(a[i]);
            }
            i++;
        }

        // Step 4: Add remaining elements from array b
        while (j < m) {
            if (result.empty() || result.back() != b[j]) {
                result.push_back(b[j]);
            }
            j++;
        }

        return result;
    }
};