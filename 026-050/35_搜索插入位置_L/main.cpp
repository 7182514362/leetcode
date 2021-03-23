#include <iostream>
#include <vector>
using namespace std;



class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if (!size) {
            return 0;
        }
        int l = 0, r = size - 1;
        int idx = size;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (target <= nums[mid]) {
                r = mid - 1;
                idx = mid;
            } else {
                l = mid + 1;
            }
        }
        return idx;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    Solution sol;
    cout << sol.searchInsert(nums, 5) << endl;
    return 0;
}