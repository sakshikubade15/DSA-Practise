// ## Count and Say Problem (C++)

// This problem generates the nth term of the count-and-say sequence.

// ### Approach
// - Start with "1"
// - Read previous string
// - Count consecutive characters
// - Form next string using count + digit

// ### Time Complexity
// Approximately O(2ⁿ)

// ### Space Complexity
// Depends on output size

// ### Example
// Input:
// n = 4

// Output:
// 1211

#include <string>
using namespace std;

class Solution {
public:
    // Function to generate count and say sequence
    string countAndSay(int n) {

        // Base case
        if (n == 1) {
            return "1";
        }

        string result = "1";

        // Generate sequence from 2 to n
        for (int i = 2; i <= n; i++) {

            string temp = "";
            int count = 1;

            for (int j = 0; j < result.length(); j++) {

                // Count same consecutive digits
                while (j + 1 < result.length() &&
                       result[j] == result[j + 1]) {
                    count++;
                    j++;
                }

                // Append count and digit
                temp += to_string(count);
                temp += result[j];

                count = 1;
            }

            result = temp;
        }

        return result;
    }
};