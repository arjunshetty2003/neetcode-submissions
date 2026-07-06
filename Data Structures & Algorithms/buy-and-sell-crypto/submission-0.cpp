class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int best = 0;
        int minBuy = INT_MAX;
        int bestBuy = 0;

        for (int i = 0; i < n; i++) {
            minBuy = min(minBuy, prices[i]);
            bestBuy = max(bestBuy, prices[i] - minBuy);
        }

        return bestBuy;
    }
};
