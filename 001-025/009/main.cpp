#include <iostream>
using namespace std;

// 判断回文数
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long tmp = x;
        long long t = tmp % 10;
        long long reverse = 0;
        while (tmp != 0) {
            reverse = reverse * 10 + t;
            tmp = (tmp - t) / 10;
            t = tmp % 10;
        }
        return ((reverse == (long long)x) ? true : false);
    }
};

// 官方
class Solution2 {
   public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNumber || x == revertedNumber / 10;
    }
};

int main() {
    Solution2 sol;
    int x = 1234567899;
    if (sol.isPalindrome(x)) {
        cout << x << " is palindrome" << endl;
    } else {
        cout << x << " is not palindrome" << endl;
    }

    return 0;
}