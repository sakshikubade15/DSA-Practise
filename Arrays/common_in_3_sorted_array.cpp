// ## Common Elements in Three Sorted Arrays (C++)

// This program finds all common elements in three sorted arrays without duplicates.

// ### Approach
// - Use three pointers (i, j, k)
// - Find minimum among current elements
// - If all equal → add to result
// - Move pointers and skip duplicates

// ### Time Complexity
// O(n1 + n2 + n3)

// ### Space Complexity
// O(1) (excluding output)

// ### Example
// Input:
// a = [1, 5, 10, 20, 40, 80]
// b = [6, 7, 20, 80, 100]
// c = [3, 4, 15, 20, 30, 70, 80, 120]

// Output:
// [20, 80]

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find common elements in three sorted arrays
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int n1 = a.size();
        int n2 = b.size();
        int n3 = c.size();

        int i = 0, j = 0, k = 0;
        vector<int> result;

        while (i < n1 && j < n2 && k < n3) {
            int currentMin = min({a[i], b[j], c[k]});

            // If all equal → common element
            if (a[i] == currentMin && b[j] == currentMin && c[k] == currentMin) {
                result.push_back(currentMin);
            }

            // Move pointers and skip duplicates
            if (a[i] == currentMin) {
                while (i < n1 && a[i] == currentMin) i++;
            }
            if (b[j] == currentMin) {
                while (j < n2 && b[j] == currentMin) j++;
            }
            if (c[k] == currentMin) {
                while (k < n3 && c[k] == currentMin) k++;
            }
        }

        return result;
    }
};