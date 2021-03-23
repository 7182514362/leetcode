
#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>>& board) {
    int i = 0;
    for (auto& v : board) {
        int j = 0;
        for (char c : v) {
            cout << c << " ";
            if (j == 2 || j == 5) {
                cout << "| ";
            }
            ++j;
        }
        cout << endl;
        if (i == 2 || i == 5) {
            cout << "------+-------+-------" << endl;
        }
        ++i;
    }
    cout << endl;
}

class Solution {
    int flag[3][9] = {0};

    void dfs(vector<vector<char>>& board, int i, int j, bool& finished) {
        if (finished || i > 8) {
            finished = true;
            return;
        }

        if (board[i][j] != '.') {
            int _i = (j == 8) ? i + 1 : i;
            int _j = (j == 8) ? 0 : j + 1;
            dfs(board, _i, _j, finished);
        } else {
            int bits =
                ~(flag[0][j] | flag[1][i] | flag[2][(i / 3) * 3 + j / 3]);
            if (!bits) return;

            for (int k = 0; k < 9; ++k) {
                int mask = 1 << k;
                if (bits & mask) {
                    char c = (char)('1' + k);

                    board[i][j] = c;
                    flag[0][j] |= mask;
                    flag[1][i] |= mask;
                    flag[2][(i / 3) * 3 + j / 3] |= mask;

                    int _i = (j == 8) ? i + 1 : i;
                    int _j = (j == 8) ? 0 : j + 1;
                    dfs(board, _i, _j, finished);
                    if (finished) {
                        return;
                    }
                    board[i][j] = '.';
                    flag[0][j] &= ~bits;
                    flag[1][i] &= ~bits;
                    flag[2][(i / 3) * 3 + j / 3] &= ~bits;
                }
            }
        }
    }

   public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];

                if (c != '.') {
                    int digit = c - '1';
                    int mask = 1 << digit;

                    flag[0][j] |= mask;
                    flag[1][i] |= mask;

                    int idx = (i / 3) * 3 + j / 3;
                    flag[2][idx] |= mask;
                }
            }
        }
        bool finished = false;
        dfs(board, 0, 0, finished);
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
    sol.solveSudoku(board);
    printBoard(board);

    return 0;
}