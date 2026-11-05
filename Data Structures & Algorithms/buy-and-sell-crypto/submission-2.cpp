class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            minBuy = min(minBuy, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minBuy);
        }
        return maxProfit;
    }
};
