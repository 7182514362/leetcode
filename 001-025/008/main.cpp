#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Solution 1
class Solution1 {
   public:
    int myAtoi(string str) {
        int len = str.size();
        if (len == 0) {
            return 0;
        }
        int idx = 0;
        while (idx < len && str.at(idx) == ' ') {
            ++idx;
        }
        if (idx >= len) return 0;
        int sign = 1;
        if (str.at(idx) == '-') {
            sign = -1;
            ++idx;
        } else if (str.at(idx) == '+') {
            ++idx;
        }
        if (idx >= len) return 0;
        long long num = 0;
        int t = idx;
        int temp = 0;
        while (idx < len) {
            temp = str.at(idx) - '0';
            if (temp >= 0 && temp <= 9)
                num = num * 10 + temp;
            else
                break;
            ++idx;
            if (sign * num > INT32_MAX) return INT32_MAX;
            if (sign * num < INT32_MIN) return INT32_MIN;
        }
        if (idx == t) {
            return 0;
        }
        num *= sign;

        return num;
    }
};

// Solution 2
enum STATE { START, SIGNED, IN_NUMBER, END };

class Automaton {
    enum STATE state = START;
    unordered_map<STATE, vector<STATE>> table = {
        {START, {START, SIGNED, IN_NUMBER, END}},
        {SIGNED, {END, END, IN_NUMBER, END}},
        {IN_NUMBER, {END, END, IN_NUMBER, END}},
        {END, {END, END, END, END}}};

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }

   public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == IN_NUMBER) {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT32_MAX)
                            : min(ans, -(long long)INT32_MIN);
        } else if (state == SIGNED)
            sign = c == '+' ? 1 : -1;
    }
};

class Solution2 {
   public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str) automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};

int main() {
    string str1 = "   -42";
    string str2 = "4193 with words";
    string str3 = "words and 987";
    string str4 = "-91283472332";
    string str5 = " ";
    string str6 = "2000000000000";
    Solution2 sol;
    cout << sol.myAtoi(str1) << endl;
    cout << sol.myAtoi(str2) << endl;
    cout << sol.myAtoi(str3) << endl;
    cout << sol.myAtoi(str4) << endl;
    cout << sol.myAtoi(str5) << endl;
    cout << sol.myAtoi(str6) << endl;
    return 0;
}