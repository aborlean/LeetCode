class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), mi = prices[0], ma = 0, profit = 0;

        for(int i = 1; i < n; i++) {
            mi = min(mi, prices[i]);
            profit = prices[i] - mi;
            ma = max(ma, profit);
        }

        return ma;
    }
};