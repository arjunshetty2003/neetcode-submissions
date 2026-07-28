class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minimumBuy = INT_MAX;
        int maxProfit = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            minimumBuy = min(minimumBuy, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minimumBuy); 
        }

        return maxProfit;
    }
};
