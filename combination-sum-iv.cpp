class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;

        for(int current = 1; current <= target; current++)
            for(int i = 0; i < nums.size(); i++) {
                int aux = nums[i];
                if(current - aux >= 0)
                    dp[current] += dp[current - aux];
            }

        return dp[target];
    }
};