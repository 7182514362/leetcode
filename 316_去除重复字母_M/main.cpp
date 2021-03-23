#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<char, int> map;
    char str[52] = {0};

   public:
    string removeDuplicateLetters(string s) {
        
    }
};

int main() {
    Solution sol;
    cout << sol.removeDuplicateLetters("cbacdcbc") << endl; // acdb
    return 0;
}