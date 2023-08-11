class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = nums.size() - 1;

        for(int j = i; j >= 0; j--)
            if(nums[j] + j >= i)
                i = j;

        if(i == 0)
            return true;
        else
            return false;
    }
};