class Solution {
public:
    int countOrders(int n) {
        vector<long long> dp(n + 1);
        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            long long count = i * (2 * i - 1);
            dp[i] = (dp[i - 1] * count) % 1000000007;
        }

        return dp[n];
    }
};