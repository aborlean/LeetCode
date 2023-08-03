class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ma = nums[0], current = 0;

        for(int i = 0; i < nums.size(); i++) {
            current = max(nums[i], current + nums[i]);
            ma = max(ma, current);
        }

        return ma;
    }
};