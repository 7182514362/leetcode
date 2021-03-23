#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        set<char> set;
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n)
        {
            // try to extend the range [i, j]
            if (set.find(s[j]) == set.end())
            {
                set.emplace(s[j++]);
                ans = ans > (j - i) ? ans : (j - i);
            }
            else
            {
                set.erase(s[i++]);
            }
        }
        return ans;
    }
};

class Solution2
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int begin = 0;
        int end = 0;
        int ret = 0;
        int length = 0;
        while (end < s.size())
        {
            char tmpChar = s[end];
            for (int i = begin; i < end; i++)
            {
                if (tmpChar == s[i])
                {
                    begin = i + 1;
                    length = end - begin;
                    break;
                }
            }
            end++;
            length++;
            ret = max(ret, length);
        }
        return ret;
    }
}; //滑动窗口

class Solution3
{
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length(), ans = 0;
        int *index = new int[128]; // current index of character
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++)
        {
            i = index[s[j]] > i ? index[s[j]] : i;
            ans = ans > (j - i + 1) ? ans : (j - i + 1);
            index[s[j]] = j + 1;
        }
        return ans;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}