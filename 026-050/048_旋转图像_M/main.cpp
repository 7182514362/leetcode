#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>> &matrix) {
        int size = matrix.size();
        if (size <= 1) {
            return;
        }
        int n = (size + 1) / 2;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < size - i - 1; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[size - j - 1][i];
                matrix[size - j - 1][i] = matrix[size - i - 1][size - j - 1];
                matrix[size - i - 1][size - j - 1] = matrix[j][size - i - 1];
                matrix[j][size - i - 1] = t;
            }
        }
    }
};

void printMatrix(vector<vector<int>> &mtx) {
    cout << "[" << endl;
    for (auto &&i : mtx) {
        for (auto &&j : i) {
            if (j >= 0)
                cout << "  " << j;
            else
                cout << " " << j;
        }
        cout << endl;
    }
    cout << "]" << endl;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    printMatrix(matrix2);
    Solution sol;
    sol.rotate(matrix2);
    printMatrix(matrix2);
    return 0;
}