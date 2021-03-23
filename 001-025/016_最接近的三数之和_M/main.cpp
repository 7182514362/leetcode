#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int ans = 0;
        int min_diff = INT32_MAX;
        for (int i = 0; i < size - 2; ++i) {
            int j = i + 1, k = size - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int temp = sum - target;
                int diff = (temp > 0) ? temp : -temp;
                ans = (diff < min_diff) ? sum : ans;
                min_diff = (diff < min_diff) ? diff : min_diff;
                k = (temp > 0) ? k - 1 : k;
                j = (temp < 0) ? j + 1 : j;
                if (temp == 0) {
                    return sum;
                }
            }
        }
        return ans;
    }
};

class Solution2 {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int ans = 0;
        int min_diff = INT32_MAX;
        for (int i = 0; i < size - 2; ++i) {
            int j = i + 1, k = size - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = (sum - target > 0) ? sum - target : target - sum;
                ans = (diff < min_diff) ? sum : ans;
                min_diff = (diff < min_diff) ? diff : min_diff;
                k = (sum - target > 0) ? k - 1 : k;
                j = (sum - target < 0) ? j + 1 : j;
                if (diff == 0) {
                    return sum;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {-1, 2, 1, -4};  // 2
    vector<int> nums2 = {0, 2, 1, -3};   //-3 0 1 2
    Solution sol;
    cout << sol.threeSumClosest(nums1, 1) << endl;
    cout << sol.threeSumClosest(nums2, 1) << endl;
    return 0;
}