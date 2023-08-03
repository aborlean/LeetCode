class Solution {
public:

    void find(int left, vector<int>& nums, vector<vector<int>>& ans) {
        if(left == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i = left; i < nums.size(); i++) {
            swap(nums[left], nums[i]);
            find(left + 1, nums, ans);
            swap(nums[i], nums[left]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        find(0, nums, ans);

        return ans;
    }
};