#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, char> charMap = {{'(', -1}, {'{', -2}, {'[', -3},
                                     {']', 3},  {'}', 2},  {')', 1}};
class Solution {
   public:
    bool isValid(string s) {
        int size = s.length();
        if (size % 2 == 1) {
            return false;
        }
        vector<char> v;
        int i = 0;
        while (i < size) {
            int code = charMap[s[i]];
            if (code < 0) {
                v.push_back(code);
            } else {
                if (!v.empty() && abs(*(v.end() - 1)) == code) {
                    v.pop_back();
                } else {
                    return false;
                }
            }
            ++i;
        }

        if (v.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s1 = (sol.isValid("()[]{}((([]{{[]}})))")) ? "true" : "false";
    string s2 = (sol.isValid("(]{")) ? "true" : "false";
    string s3 = (sol.isValid("([)]")) ? "true" : "false";
    string s4 = (sol.isValid("]")) ? "true" : "false";
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    return 0;
}