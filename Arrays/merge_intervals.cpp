// ## Merge Intervals (C++)

// This problem merges all overlapping intervals.

// ### Approach
// 1. Sort intervals based on starting time
// 2. Initialize start and end from first interval
// 3. Traverse:
//    - If overlapping → update end
//    - Else → push interval and reset start/end
// 4. Add last interval

// ### Time Complexity
// O(n log n)  (due to sorting)

// ### Space Complexity
// O(n)

// ### Example
// Input:
// [[1,3],[2,6],[8,10],[15,18]]

// Output:
// [[1,6],[8,10],[15,18]]

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to merge overlapping intervals
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Edge case
        if (intervals.empty()) return {};

        // Step 1: Sort intervals based on starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        int start = intervals[0][0];
        int end = intervals[0][1];

        // Step 2: Traverse intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                // Overlapping → merge
                end = max(end, intervals[i][1]);
            } else {
                // Non-overlapping → store previous interval
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        // Add last interval
        result.push_back({start, end});

        return result;
    }
};