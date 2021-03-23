#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        
    }
};

// 排序+双指针
class Solution2 {
   public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {}
};

void printMatrix(vector<vector<int>> &&mtx) {
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
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    Solution sol;
    printMatrix(sol.fourSum(nums1, 0));
    return 0;
}