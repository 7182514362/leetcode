#include <iostream>
#include <vector>
using namespace std;

// 官方--顺序+倒序
class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n);
        for (int i = 0; i < n; i++) {
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }
        int right = 0, ret = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }
            ret += max(left[i], right);
        }
        return ret;
    }
};

class Solution2 {
   public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        int ans = 1;
        int asc = 1;  // ascend len
        int asc_ = asc;
        int dec = 0;  // descend len

        for (int i = 1; i < size; ++i) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                asc = (ratings[i] == ratings[i - 1]) ? 1 : asc + 1;
                asc_ = asc;
                ans += asc;
            } else {
                asc = 1;
                ++dec;
                if (asc_ == dec) {
                    ++dec;
                }
                ans += dec;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> ratings = {1, 2, 2};  // 1,2,3,4,1,5,4,3,2,1
    Solution2 sol;
    cout << sol.candy(ratings) << endl;
    return 0;
}