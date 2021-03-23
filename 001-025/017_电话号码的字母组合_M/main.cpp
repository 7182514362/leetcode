#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// dfs
unordered_map<char, string> digitMap = {
    {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        vector<string> ans;
        if (len == 0) {
            return ans;
        }
        string combition;
        f(ans, combition, digits, 0);
        return ans;
    }

    static void f(vector<string>& combinations, string& combination,
                  string& digits, int digitIdx) {
        if (digitIdx == digits.length()) {
            combinations.push_back(combination);
        } else {
            for (auto& ch : digitMap[digits[digitIdx]]) {
                combination.push_back(ch);
                f(combinations, combination, digits, digitIdx + 1);
                combination.pop_back();
            }
        }
    }
};

void printStrs(vector<string>& strs) {
    for (auto& s : strs) {
        cout << s << endl;
    }
}

int main() {
    Solution sol;
    auto ans = sol.letterCombinations("5678");
    sort(ans.begin(), ans.end());
    printStrs(ans);

    return 0;
}