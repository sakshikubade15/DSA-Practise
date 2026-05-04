// ## Factorial of Large Number (C++)

// This program computes factorial of large numbers using digit-by-digit multiplication.


// ### Approach
// - Store result as a vector of digits
// - Multiply each number from 2 to n
// - Handle carry during multiplication

// ### Time Complexity
// O(n²)

// ### Space Complexity
// O(number of digits)

// ### Example
// Input:
// n = 10

// Output:
// 3628800

#include <vector>
using namespace std;

class Solution {
public:
    // Function to find factorial of a large number
    vector<int> factorial(int n) {
        vector<int> result;
        result.push_back(1); // initialize with 1

        for (int i = 2; i <= n; i++) {
            multiply(result, i);
        }

        // Reverse to get correct order
        reverse(result.begin(), result.end());
        return result;
    }

private:
    // Helper function to multiply a number with result
    void multiply(vector<int> &result, int x) {
        int carry = 0;

        for (int i = 0; i < result.size(); i++) {
            int prod = result[i] * x + carry;
            result[i] = prod % 10;
            carry = prod / 10;
        }

        // Handle remaining carry
        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
};