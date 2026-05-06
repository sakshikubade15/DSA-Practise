// ## Elements Occurring More Than n/k Times (C++)

// This program finds all elements that appear more than n/k times in an array.

// ### Approach (Hash Map)
// - Count frequency of each element
// - Print elements with frequency > n/k

// ### Time Complexity
// O(n)

// ### Space Complexity
// O(n)

// ### Example
// Input:
// [3, 4, 2, 2, 1, 2, 3, 3], k = 4

// Output:
// 2, 3


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to print elements appearing more than n/k times
void moreThanNdK(vector<int> &arr, int k) {
    int n = arr.size();

    unordered_map<int, int> freq;

    // Count frequency
    for (int num : arr) {
        freq[num]++;
    }

    // Print elements with freq > n/k
    for (auto it : freq) {
        if (it.second > n / k) {
            cout << "Element: " << it.first 
                 << " Count: " << it.second << endl;
        }
    }
}

int main() {
    vector<int> arr = {3, 4, 2, 2, 1, 2, 3, 3};
    int k = 4;

    moreThanNdK(arr, k);
    return 0;
}