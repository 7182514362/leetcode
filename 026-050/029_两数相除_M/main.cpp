#include <iostream>

using namespace std;

class Solution {
   public:
    // divisor!=0
    int divide(int dividend, int divisor) {
        if (dividend == INT32_MIN) {
            if (divisor == -1) return INT32_MAX;
            if (divisor == 1) return dividend;
        }
        // 算术右移补符号位
        int sign = ((dividend ^ divisor) >> 31) < 0 ? -1 : 1;

        // a b 取负数避免超限
        unsigned int a =
            (dividend >= 0) ? dividend : (unsigned)(-(dividend + 1)) + 1;
        unsigned int b =
            (divisor >= 0) ? divisor : (unsigned)(-(divisor + 1)) + 1;

        unsigned int ans = 0;
        unsigned int i = 1;
        unsigned int t = b;
        while (a >= t) {
            // a > 2t ?
            while (a - t >= t) {
                t = t << 1;
                i = i << 1;
            }
            // a > t
            a -= t;
            t = b;
            ans += i;
            i = 1;
        }
        int result = (sign > 0) ? ans : -(int)ans;
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.divide(INT32_MIN, 1) << endl;
    return 0;
}