// ## Check Whether One String is Rotation of Another (C++)

// This program checks whether one string is rotation of another.

// ### Approach
// - Lengths must be equal
// - Concatenate first string with itself
// - Check if second string exists as substring

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(n)

// ### Example
// Input:
// s1 = "abcd"
// s2 = "cdab"

// Output:
// true

#include <string>
using namespace std;

class Solution {
public:
    // Function to check if strings are rotations
    bool areRotations(string &s1, string &s2) {

        // Length must be same
        if (s1.length() != s2.length()) {
            return false;
        }

        // Concatenate first string with itself
        string temp = s1 + s1;

        // Check if s2 exists in temp
        return (temp.find(s2) != string::npos);
    }
};