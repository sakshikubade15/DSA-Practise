// ## Sort 0s, 1s and 2s (Dutch National Flag Algorithm)

// This problem sorts an array containing only 0s, 1s, and 2s in a single pass.

// ### Approach
// - Use three pointers: low, mid, high
// - Traverse array once and rearrange elements

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Key Concept
// Dutch National Flag Algorithm


#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int low = 0;              // for 0s
        int mid = 0;              // current element
        int high = arr.size() - 1; // for 2s

        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                mid++;
            }
            else { // arr[mid] == 2
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};