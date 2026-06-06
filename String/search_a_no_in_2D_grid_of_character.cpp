// ## Search a Word in a 2D Grid (C++)

// Given a 2D grid of characters and a word,
// find all starting positions where the word exists.

// The word can be searched in all 8 directions.

// ### Approach
// - Traverse every cell
// - If first character matches:
//   check all 8 directions
// - Store valid starting positions

// ### Time Complexity
// O(N × M × 8 × L)

// ### Space Complexity
// O(1)


#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    // 8 possible directions
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    bool searchWord(vector<vector<char>>& grid,
                    int row,
                    int col,
                    string word) {

        int n = grid.size();
        int m = grid[0].size();

        // Check all directions
        for (int dir = 0; dir < 8; dir++) {

            int x = row;
            int y = col;

            int k;

            for (k = 0; k < word.length(); k++) {

                if (x < 0 || x >= n ||
                    y < 0 || y >= m ||
                    grid[x][y] != word[k]) {
                    break;
                }

                x += dx[dir];
                y += dy[dir];
            }

            // Entire word matched
            if (k == word.length()) {
                return true;
            }
        }

        return false;
    }

    vector<vector<int>> searchWord(
        vector<vector<char>>& grid,
        string word) {

        vector<vector<int>> ans;

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == word[0] &&
                    searchWord(grid, i, j, word)) {

                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};