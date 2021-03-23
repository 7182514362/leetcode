#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, satisfied = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                ++satisfied;
                ++j;
                ++i;
            } else {
                ++j;
            }
        }
        return satisfied;
    }
};

int main() {
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};
    Solution sol;
    cout << sol.findContentChildren(g, s) << endl;
    return 0;
}