// ## Roman Number to Integer (C++)

// Convert a Roman numeral into its decimal value.

// ### Rule

// If current symbol value is less than next symbol value:
// Subtract it.

// Otherwise:
// Add it.

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example

// Input:
// MCMIV

// Output:
// 1904

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToDecimal(string &s) {

        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {

            if (i < n - 1 &&
                mp[s[i]] < mp[s[i + 1]]) {

                ans -= mp[s[i]];
            }
            else {
                ans += mp[s[i]];
            }
        }

        return ans;
    }
};