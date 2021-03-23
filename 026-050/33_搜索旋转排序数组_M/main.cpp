#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return -1;
        }
        int l = 0, r = size - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            //
            if (nums[l] <= nums[mid]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums = {3, 1};
    Solution sol;
    cout << sol.search(nums, 1) << endl;
    return 0;
}