// ## Convert Sentence to Mobile Numeric Keypad Sequence

// Given a sentence containing uppercase letters and spaces,
// convert it into the equivalent mobile numeric keypad sequence.

// ### Keypad Mapping

// 2 → ABC
// 3 → DEF
// 4 → GHI
// 5 → JKL
// 6 → MNO
// 7 → PQRS
// 8 → TUV
// 9 → WXYZ
// 0 → Space

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(n)

// ### Example

// Input:
// HELLO WORLD

// Output:
// 4433555555666096667775553## Convert Sentence to Mobile Numeric Keypad Sequence

// Given a sentence containing uppercase letters and spaces,
// convert it into the equivalent mobile numeric keypad sequence.

// ### Keypad Mapping

// 2 → ABC
// 3 → DEF
// 4 → GHI
// 5 → JKL
// 6 → MNO
// 7 → PQRS
// 8 → TUV
// 9 → WXYZ
// 0 → Space

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(n)

// ### Example

// Input:
// HELLO WORLD

// Output:
// 44335555556660966677755#include <string>
using namespace std;

class Solution {
public:
    string printSequence(string S) {

        string keypad[] = {
            "2",    "22",   "222",   // A, B, C
            "3",    "33",   "333",   // D, E, F
            "4",    "44",   "444",   // G, H, I
            "5",    "55",   "555",   // J, K, L
            "6",    "66",   "666",   // M, N, O
            "7",    "77",   "777",   "7777", // P,Q,R,S
            "8",    "88",   "888",   // T,U,V
            "9",    "99",   "999",   "9999"  // W,X,Y,Z
        };

        string ans = "";

        for (char ch : S) {

            if (ch == ' ') {
                ans += "0";
            }
            else {
                ans += keypad[ch - 'A'];
            }
        }

        return ans;
    }
};

