#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution1 {
   public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (numRows == 1) {
            return s;
        }
        vector<string> vec(numRows);
        int idx = 0;
        bool flag = true;
        int row = 0;
        while (idx < len) {
            vec[row].push_back(s[idx++]);
            if (flag) {
                ++row;
            } else {
                --row;
            }
            if (row >= (numRows - 1) || row <= 0) {
                flag = !flag;
            }
        }
        for (int i = 1; i < numRows; ++i) {
            vec[0].append(vec[i]);
        }

        return vec[0];
    }
};

class Solution2 {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int len = s.size();
        int max_step = 2 * numRows-2;
        int step1 = max_step+2, step2 = -2;
        int idx1 = 0, idx2 = 0;
        string result(s);
        for (int i = 0; i < numRows; ++i) {
            idx2 = i;
            step1 -= 2;
            step2 += 2;
            bool flag = true;
            if(i==(numRows-1))
                flag=false;
            while (idx2 < len) {
                result[idx1++] = s.at(idx2);
                if (flag) {
                    idx2 += step1;
                } else {
                    idx2 += step2;
                }
                if(i!=0 && i!=(numRows-1))
                    flag = !flag;
            }
        }
        return result;
    }
};

int main() {
    string str = "PAYPALISHIRING";
    Solution2 sol;
    clock_t start = clock();
    string result = sol.convert(str, 3);
    clock_t end = clock();
    cout << result << endl;
    cout << (double)(end - start) / (CLOCKS_PER_SEC) << endl;

    return 0;
}