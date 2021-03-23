#include <deque>
#include <iostream>
using namespace std;

class Solution {
   public:
    string countAndSay(int n) {
        if (n <= 0) {
            return string();
        }
        deque<char> q;
        q.push_back('1');
        for (int i = 0; i < n - 1; ++i) {
            int len = q.size();
            int j = 0;
            while (j < len) {
                char pre_c = q.front();
                int count = 0;
                while (j < len && pre_c == q.front()) {
                    ++count;
                    q.pop_front();
                    ++j;
                }
                char c = '0' + count;
                q.push_back(c);
                q.push_back(pre_c);
            }
        }
        return string(q.begin(), q.end());
    }
};

class Solution2 {
    // const char* itoa[20] = {"0", "1", "2", "3", "4", "5","6", "7", "8", "9",
    // "10"};
    int itoa(char* s, int a) {
        int i = 0;
        while (a) {
            int digit = a % 10;
            s[i++] = digit + '0';
            a /= 10;
        }
        s[i] = 0;
        return i;
    }

   public:
    string countAndSay(int n) {
        if (n <= 0) {
            return string();
        }
        deque<char> q;
        q.push_back('1');
        for (int i = 0; i < n - 1; ++i) {
            int len = q.size();
            int j = 0;
            while (j < len) {
                char pre_c = q.front();
                int count = 0;
                while (j < len && pre_c == q.front()) {
                    ++count;
                    q.pop_front();
                    ++j;
                }
                char s[256];
                int size = itoa(s, count);
                for (int k = size - 1; k >= 0; --k) {
                    q.push_back(s[k]);
                }
                q.push_back(pre_c);
            }
        }

        return string(q.begin(), q.end());
    }
};

int main() {
    Solution sol;
    cout << sol.countAndSay(30) << endl;
    return 0;
}