#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int flag[3][9] = {0};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];

                if (c != '.') {
                    int digit = c - '1';
                    int mask = 1 << digit;

                    // column flag
                    int bit1 = flag[0][j] & mask;
                    if (bit1) return false;
                    flag[0][j] |= mask;

                    // row flag
                    int bit2 = flag[1][i] & mask;
                    if (bit2) return false;
                    flag[1][i] |= mask;

                    int idx = (i / 3) * 3 + j / 3;
                    int bit3 = flag[2][idx] & mask;
                    if (bit3) return false;
                    flag[2][idx] |= mask;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> board2 = {
        {'.', '8', '7', '6', '5', '4', '3', '2', '1'},
        {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'9', '.', '.', '.', '.', '.', '.', '.', '.'}};

    Solution sol;
    cout << sol.isValidSudoku(board2) << endl;
    return 0;
}