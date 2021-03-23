#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// const char* symbols[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
// int values[7] = {1000, 500, 100, 50, 10, 5, 1};

unordered_map<char, int> symbolMap = {{'M', 1000}, {'D', 500}, {'C', 100},
                                      {'L', 50},   {'X', 10},  {'V', 5},
                                      {'I', 1}};

class Solution {
   public:
    int romanToInt(string s) {
        int len = s.length();
        const char* p = s.c_str() + len - 1;
        int ans = symbolMap[*p];
        for (int i = len; i > 1; --i) {
            char c_pre = *(p - 1);
            int val_pre = symbolMap[c_pre];
            ans = (symbolMap[*p] > val_pre) ? ans - val_pre : ans + val_pre;
            --p;
        }
        return ans;
    }
};

class Solution2 {
   public:
    int romanToInt(string s) {
        int ans = 0;
        int len = s.length();
        const char* p = s.c_str();
        for (int i = 1; i < len; ++i) {
            int v1 = symbol2int(s[i - 1]);
            int v2 = symbol2int(s[i]);
            ans = (v1 < v2) ? ans - v1 : ans + v1;
        }
        ans += symbol2int(s[len - 1]);
        return ans;
    }

    int symbol2int(char c) {
        int ans;
        switch (c) {
            case 'M':
                ans = 1000;
                break;
            case 'D':
                ans = 500;
                break;
            case 'C':
                ans = 100;
                break;
            case 'L':
                ans = 50;
                break;
            case 'X':
                ans = 10;
                break;
            case 'V':
                ans = 5;
                break;
            case 'I':
                ans = 1;
                break;
            default:
                ans = 0;
                break;
        }
        return ans;
    }
};

int main() {
    Solution2 sol;
    cout << sol.romanToInt("MCMXCIV") << endl;  // 1994
    cout << sol.romanToInt("LVIII") << endl;    // 58
    return 0;
}
