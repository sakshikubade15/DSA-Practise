// ## Rabin-Karp Algorithm (C++)

// Rabin-Karp is a string matching algorithm based on hashing.

// ### Steps
// 1. Compute hash of pattern.
// 2. Compute hash of first window.
// 3. Compare hashes.
// 4. If hashes match, verify characters.
// 5. Slide window and update hash.

// ### Time Complexity
// Average: O(n + m)

// Worst: O(n × m)

// ### Space Complexity
// O(1)
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void rabinKarp(string text, string pattern) {

        int n = text.length();
        int m = pattern.length();

        int d = 256;     // Number of characters
        int q = 101;     // Prime number

        int pHash = 0;   // Pattern hash
        int tHash = 0;   // Text window hash
        int h = 1;

        // Calculate h = pow(d, m-1) % q
        for (int i = 0; i < m - 1; i++) {
            h = (h * d) % q;
        }

        // Initial hash values
        for (int i = 0; i < m; i++) {
            pHash = (d * pHash + pattern[i]) % q;
            tHash = (d * tHash + text[i]) % q;
        }

        // Slide pattern over text
        for (int i = 0; i <= n - m; i++) {

            // Hashes match
            if (pHash == tHash) {

                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    cout << "Pattern found at index "
                         << i << endl;
                }
            }

            // Calculate next window hash
            if (i < n - m) {

                tHash = (d * (tHash - text[i] * h)
                         + text[i + m]) % q;

                if (tHash < 0) {
                    tHash += q;
                }
            }
        }
    }
};