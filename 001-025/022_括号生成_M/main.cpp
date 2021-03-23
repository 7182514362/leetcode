#include <iostream>
#include <vector>
using namespace std;

class Solution {
   private:
    void DFS(vector<string> &combinations, string &combination, int n,
             int depth, int bias) {
        if (bias < 0 || bias > n) {
            return;
        }
        if (bias == 0 && depth == n * 2) {
            combinations.push_back(combination);
        }
        if (depth != n * 2) {
            combination.push_back('(');
            DFS(combinations, combination, n, depth + 1, bias + 1);
            combination.pop_back();

            combination.push_back(')');
            DFS(combinations, combination, n, depth + 1, bias - 1);
            combination.pop_back();
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        string combination;
        DFS(combinations, combination, n, 0, 0);
        return combinations;
    }
};

// 官方
// 最终 open==n close==n
class Solution2 {
    void backtrack(vector<string> &ans, string &cur, int open, int close,
                   int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};

void printStrs(vector<string> &&strs) {
    for (string &s : strs) {
        cout << s << endl;
    }
}

int main() {
    Solution sol;
    printStrs(sol.generateParenthesis(3));
    return 0;
}