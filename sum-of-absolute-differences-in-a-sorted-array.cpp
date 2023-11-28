class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int sum = 0, current = 0;

        for(auto x : nums)
            sum += x;

        for(int i = 0; i < nums.size(); i++) {
            current += nums[i];
            int l = (nums[i] * (i + 1) - current);
            int r = (sum - current) - (nums[i] * (nums.size() - i - 1));
            ans.push_back(l + r);
        }

        return ans;
    }
};