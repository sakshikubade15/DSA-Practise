// ## Check Whether One Array is Subset of Another (C++)

// This program checks whether one array is a subset of another.

// ### Approach
// - Store elements of first array in a hash set
// - Traverse second array
// - If any element is missing → return false

// ### Time Complexity
// O(n + m)

// ### Space Complexity
// O(n)

// ### Example
// Input:
//  b = [11, 3, 7, 1]

// Output:
// // true

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Function to check if array b is subset of array a
    bool isSubset(vector<int>& a, vector<int>& b) {

        unordered_set<int> st;

        // Store all elements of array a
        for (int num : a) {
            st.insert(num);
        }

        // Check every element of b
        for (int num : b) {
            if (st.find(num) == st.end()) {
                return false;
            }
        }

        return true;
    }
};