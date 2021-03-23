#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return string("");
        }
        string& s = strs[0];
        int len = s.length();
        if (len == 0) {
            return string("");
        }
        int i;
        for (i = 0; i < len; ++i) {
            char c = s[i];
            for (auto it = strs.begin() + 1; it != strs.end(); ++it) {
                if (c != (*it)[i]) {
                    return s.substr(0, i);
                }
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    vector<string> vec = {"flower", "flow", "flight"};
    vector<string> vec2 = {"dog", "racecar", "car"};
    vector<string> vec3 = {"", "racecar", "car"};
    vector<string> vec4;
    cout << sol.longestCommonPrefix(vec) << endl;
    cout << sol.longestCommonPrefix(vec2) << endl;
    cout << sol.longestCommonPrefix(vec3) << endl;
    cout << sol.longestCommonPrefix(vec4) << endl;
    return 0;
}