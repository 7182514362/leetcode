#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> values;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size < 3) {
            return values;
        }
        int preVal_i = nums[0] - 1;
        for (int i = 0; i < size; ++i) {
            // 避免重复
            int val_i = nums[i];
            if (preVal_i == val_i) {
                continue;
            }
            preVal_i = val_i;

            int val = 0 - val_i;
            // avoid preVal_j==nums[k] when k==size-1
            int preVal_j = nums[i] - 1;
            int k = size - 1;
            for (int j = i + 1; j < k;) {
                int val_j = nums[j];
                if (preVal_j == val_j) {
                    ++j;
                    continue;
                }

                int val_k = nums[k];
                int val2 = val_j + val_k;
                if (val2 < val) {
                    ++j;
                    preVal_j = val_j;
                } else if (val2 > val) {
                    --k;
                } else {
                    values.push_back({val_i, val_j, val_k});
                    ++j;
                    preVal_j = val_j;
                }
            }
        }
        return values;
    }
};

class Solution2 {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        
    }
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
    
    vector<int> nums1 = {0, 0, 0, 0};
    vector<int> nums2 = {-1, 0, 1, 2, -1, -4};
    vector<int> nums3 = {1, 2, -2, 1};
    Solution sol;
    printMatrix(sol.threeSum(nums1));
    printMatrix(sol.threeSum(nums2));
    printMatrix(sol.threeSum(nums3));
    
/*
    vector<int> nums4 = {-1, 0, 1, 2, -1, -4};
    Solution2 sol2;
    printMatrix(sol2.threeSum(nums4));
*/
    return 0;
}