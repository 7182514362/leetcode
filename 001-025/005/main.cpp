#include <string.h>

#include <iostream>
#include <string>

using namespace std;

class Solution1 {
   public:
    string longestPalindrome(string s) {
        int len = s.size();
        char a[1000][1000];

        int max_len = 1;
        int last_i = 0, last_j = 0;
        for (int i = len - 1; i >= 0; --i) {
            a[i][i] = 1;
            if (i < len - 2) {
                if (s[i] == s[i + 1])
                    a[i][i + 1] = 1;
                else
                    a[i][i + 1] = 0;
            }
            for (int j = i + 2; j < len; ++j) {
                a[i][j] = (s[i] == s[j]) ? a[i + 1][j - 1] : 0;
                int t = j - i + 1;
                if (a[i][j] && max_len < t) {
                    last_i = i;
                    last_j = j;
                    max_len = t;
                }
            }
        }
        return s.substr(last_i, (last_j - last_i + 1));
    }
};

class Solution2 {
   public:
    string longestPalindrome(string s) {
        int len = s.size();
        int max_len = 1;
        int pos = 0;
        int left = 0, right = 0;
        int last_left = 0, last_right = 0;
        while (pos < len - 1) {
            left = pos;
            right = pos;
            while (left >= 0 && right < len && s[left] == s[right]) {
                --left;
                ++right;
            }
            int cur_len = right - left - 1;
            if (cur_len > max_len) {
                max_len = cur_len;
                last_left = ++left;
                //last_right = --right;
            }

            left = pos;
            right = pos + 1;
            while (left >= 0 && right < len && s[left] == s[right]) {
                --left;
                ++right;
            }
            int cur_len2 = right - left - 1;
            if (cur_len2 > max_len) {
                max_len = cur_len2;
                last_left = ++left;
                //last_right = --right;
            }
            ++pos;
        }
        return s.substr(last_left,max_len);
    }
};

int main() {
    string s = "babad";
    Solution2 solu;
    string substr = solu.longestPalindrome(s);
    cout << substr << endl;
    return 0;
}