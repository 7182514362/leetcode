#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        char arr_s[256] = {0};
        char arr_t[256] = {0};

        for (int i = 0; i < s.size(); ++i) {
            if (arr_s[s[i]] == 0 && arr_t[t[i]] == 0) {
                arr_s[s[i]] = t[i];
                arr_t[t[i]] = s[i];
            } else if (arr_s[s[i]] != t[i] || arr_t[t[i]] != s[i]) {
                return false;
            } else {
            }
        }
        return true;
    }
};

class Solution2 {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;

        for (int i = 0; i < s.size(); ++i) {
            if (map1.find(s[i]) == map1.end() &&
                map2.find(t[i]) == map2.end()) {
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            } else if (map1[s[i]] != t[i] || map2[t[i]] != s[i]) {
                return false;
            } else {
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isIsomorphic("egg", "add") << endl;
    return 0;
}