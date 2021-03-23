#include <iostream>

using namespace std;

class Solution {
    char set[26] = {0};

   public:
    char findTheDifference(string s, string t) {
        for (int i = 0; i < s.length(); ++i) {
            ++set[s[i] - 'a'];
        }

        for (int i = 0; i < t.length(); ++i) {
            --set[t[i] - 'a'];
            if (set[t[i] - 'a'] < 0) {
                return t[i];
            }
        }

        return 0;
    }
};

// 官方 求和
class Solution2 {
   public:
    char findTheDifference(string s, string t) {
        int as = 0, at = 0;
        for (char ch : s) {
            as += ch;
        }
        for (char ch : t) {
            at += ch;
        }
        return at - as;
    }
};

// 异或
class Solution3 {
   public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for (char ch : s) {
            ret ^= ch;
        }
        for (char ch : t) {
            ret ^= ch;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    cout << sol.findTheDifference("abcd", "abccd") << endl;
    return 0;
}