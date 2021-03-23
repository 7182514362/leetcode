#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        int h_l = 0, h_r = 0;
        while (l < r) {
            h_l = height[l];
            h_r = height[r];
            int area = min(h_l, h_r) * (r - l);
            ans = max(ans, area);
            if (height[l] <= height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v({1, 8, 6, 2, 5, 4, 8, 3, 7}), v1({1, 1}), v2({4, 3, 2, 1, 4}),
        v3({1, 2, 1}), v4({2, 3, 4, 5, 18, 17, 6});
    Solution sol;
    // cout << sol.maxArea(v) << endl;
    // cout << sol.maxArea(v1) << endl;
    // cout << sol.maxArea(v2) << endl;
    // cout << sol.maxArea(v3) << endl;
    cout << sol.maxArea(v4) << endl;

    return 0;
}