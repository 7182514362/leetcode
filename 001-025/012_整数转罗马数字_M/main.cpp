
#include <iostream>
using namespace std;

string a[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
string b[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
string c[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
string d[4] = {"", "M", "MM", "MMM"};

// 硬编码
class Solution {
   public:
    string intToRoman(int num) {
        return d[num / 1000] + c[num % 1000 / 100] + b[num % 100 / 10] +
               a[num % 10];
    }
};

// 贪心
int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const char* symbols[13] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                           "XL", "X",  "IX", "V",  "IV", "I"};

class Solution2 {
   public:
    string intToRoman(int num) {
        char roman[20];
        int idx = 0;
        for (int i = 0; i < 13; ++i) {
            int v = values[i];
            while (v <= num) {
                num -= v;
                int size = (i % 2) ? 2 : 1;
                char* p = (char*)symbols[i];
                while (size) {
                    roman[idx++] = *p;
                    ++p;
                    --size;
                }
            }
        }
        roman[idx] = 0;
        return string(roman);
    }
};

int main() {
    Solution2 sol;
    cout << sol.intToRoman(3999) << endl;
    cout << sol.intToRoman(9) << endl;
    return 0;
}