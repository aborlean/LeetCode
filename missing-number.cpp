class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = 0ll;

        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];

        return nums.size() * (nums.size() + 1) / 2 - sum;
    }
};