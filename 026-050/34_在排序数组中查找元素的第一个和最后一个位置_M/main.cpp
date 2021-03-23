#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> ans;
        if (!size) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        int l = 0, r = size - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                ans.push_back(mid);
                break;
            } else if (target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (ans.empty()) {
            ans.push_back(-1);
            ans.push_back(-1);
        } else {
            int first = ans[0];
            int last = ans[0];
            while (--first >= 0 && nums[first] == target) {
            }
            while (++last < size && nums[last] == target) {
            }
            ans.pop_back();
            ans.push_back(first + 1);
            ans.push_back(last - 1);
        }

        return ans;
    }
};

// 官方-巧用二分
class Solution2 {
   public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() &&
            nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx};
        }
        return vector<int>{-1, -1};
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution sol;
    auto v = sol.searchRange(nums, 6);
    for (int i : v) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}