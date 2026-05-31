// ## Balanced Parentheses (C++)

// Given a string containing brackets:
// (), {}, []

// Check whether the brackets are balanced.

// ### Approach
// - Use stack
// - Push opening brackets
// - Match and pop on closing brackets
// - Stack should be empty at the end

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(n)

// ### Example
// Input:
// "{([])}"

// Output:
// true
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isBalanced(string& s) {

        stack<char> st;

        for (char ch : s) {

            // Opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // Closing brackets
            else {

                if (st.empty()) {
                    return false;
                }

                if ((ch == ')' && st.top() == '(') ||
                    (ch == '}' && st.top() == '{') ||
                    (ch == ']' && st.top() == '[')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};