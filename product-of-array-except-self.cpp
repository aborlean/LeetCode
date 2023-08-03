class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;

        int left = 1;
        for(int i = 0; i < nums.size(); i++) {
            ans.push_back(left);
            left *= nums[i];
        }

        int right = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};