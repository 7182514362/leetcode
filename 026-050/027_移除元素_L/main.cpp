#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int i = 0;
        int j = 0;
        while (i < len) {
            if (nums[i] != val) {
                nums[j++] = nums[i];
            }
            ++i;
        }
        return j;
    }
};

// 官方 删除元素较少
class Solution2 {
   public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums2 = {3, 2, 2, 3};
    Solution sol;
    cout << sol.removeElement(nums, 3) << endl;
    cout << sol.removeElement(nums2, 3) << endl;
    return 0;
}