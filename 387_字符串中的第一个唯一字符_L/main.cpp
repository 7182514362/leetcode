#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    int firstUniqChar(string s) {
        int size = s.size();
        if (size == 0) {
            return -1;
        }
        int idxOf[26] = {0};
        for (int i = 0; i < size; ++i) {
            if (idxOf[s[i] - 'a'] == 0) {
                idxOf[s[i] - 'a'] = i + 1;
            } else {
                idxOf[s[i] - 'a'] = -1;
            }
        }
        int idx = size + 1;
        for (int i = 0; i < 26; ++i) {
            int t = idxOf[i];
            if (t > 0 && t < idx) {
                idx = t;
            }
        }
        return (idx == size + 1) ? -1 : idx - 1;
    }
};

class Solution2 {
   public:
    int firstUniqChar(string s) {
        int size = s.size();
        int count[26] = {0};
        for (int i = 0; i < size; ++i) {
            ++count[s[i] - 'a'];
        }

        for (int i = 0; i < size; ++i) {
            if (1 == count[s[i] - 'a']) return i;
        }
        return -1;
    }
};

int main() {
    Solution2 sol;
    cout << sol.firstUniqChar("loveleetcode") << endl;
    return 0;
}