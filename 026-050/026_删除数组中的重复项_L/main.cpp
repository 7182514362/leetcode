#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        int i = 0;
        int val = nums[0];
        for (int j = 1; j < len; ++j) {
            if (nums[j] != val) {
                nums[++i] = nums[j];
                val = nums[j];
            }
        }
        return ++i;
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums2 = {0, 0, 0, 0, 0, 0, 0};
    Solution sol;
    cout << sol.removeDuplicates(nums) << endl;
    cout << sol.removeDuplicates(nums2) << endl;
    return 0;
}