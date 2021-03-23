#include <iostream>
#include <vector>
using namespace std;

void printPrices(vector<int>& prices) {
    for (int i : prices) {
        cout << i << " ";
    }
    cout << endl;
}

// 官方 动态规划
class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
    int maxProfit2(vector<int>& prices, int fee) {
        int n = prices.size();
        int sell = 0, buy = -prices[0];
        for (int i = 1; i < n; ++i) {
            sell = max(sell, buy + prices[i] - fee);
            buy = max(buy, sell - prices[i]);
        }
        return sell;
    }
};

int main() {
    vector<int> prices1 = {1, 3, 2, 8, 7, 5, 4, 9};
    vector<int> prices2 = {5, 4, 3, 2, 1, 0};
    Solution sol;
    cout << sol.maxProfit(prices1, 2) << endl;
    cout << sol.maxProfit2(prices1, 2) << endl;
    cout << sol.maxProfit(prices2, 3) << endl;
    return 0;
}