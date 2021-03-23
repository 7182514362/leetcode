#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    // 翻转数组
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            int t = nums[l];
            nums[l] = nums[r];
            nums[r] = t;
            ++l;
            --r;
        }
    }

   public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) {
            --i;
        }
        if (i == 0) {
            reverse(nums, 0, size - 1);
            return;
        }

        int num = nums[i - 1];
        int j = i;
        while (j < size && nums[j] > num) {
            ++j;
        }
        int t = nums[j - 1];
        nums[j - 1] = nums[i - 1];
        nums[i - 1] = t;
        // 降序变升序
        reverse(nums, i, size - 1);
    }
};

void printVector(vector<int>& v) {
    for (int i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> nums = {8, 4, 5, 7, 6, 3, 3, 2, 1};  // 8,4,5,7,6,3,2,1
    Solution sol;
    sol.nextPermutation(nums);
    printVector(nums);
    return 0;
}