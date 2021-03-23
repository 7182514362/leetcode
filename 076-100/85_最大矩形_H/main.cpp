#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int maxRect(vector<vector<char>>& matrix, int _i, int _j, int rows,
                int cols) {
        int max = 0;
        int i = _i;
        while (i < rows && matrix[i][_j] == '1') {
            ++i;
        }
        i = (i >= rows) ? rows - 1 : i;

                for (int i = _i; i < rows; ++i) {
        }
    }

   public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
            }
        }
    }
};

int main() {
    Solution sol;
    return 0;
}