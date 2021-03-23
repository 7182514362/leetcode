#include <cmath>
#include <iostream>
using namespace std;

class Solution {
   public:
    int reverse(int x) {
        int sign = 1;
        if (x == INT32_MIN) {
            return 0;
        }
        if (x < 0) {
            sign = -1;
            x = 0 - x;
        }
        long long result = 0;
        while (x > 0) {
            result = result * 10 + x % 10;
            // the condition is always false
            // if (sign < 0 && (result - 1) > INT32_MAX) return 0;
            x /= 10;
        }
        if (result > INT32_MAX) return 0;
        return result * sign;
    }
};

int main() {
    Solution sol;
    cout << sol.reverse(INT32_MIN) << endl;
    cout << -12 % 10 << endl;
    return 0;
}