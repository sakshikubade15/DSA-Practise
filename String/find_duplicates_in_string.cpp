// ## Find Duplicate Characters in a String (C++)

// This program finds all duplicate characters in a string.

// ### Approach
// - Use hashmap to count frequency
// - Print characters with frequency > 1

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(1)

// ### Example
// Input:
// "programming"

// Output:
// r -> 2
// g -> 2
// m -> 2
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function to print duplicate characters
    void findDuplicates(string s) {

        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Print duplicates
        for (auto it : freq) {
            if (it.second > 1) {
                cout << it.first << " -> " << it.second << endl;
            }
        }
    }
};