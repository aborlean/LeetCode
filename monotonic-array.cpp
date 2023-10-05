class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() < 2)
            return true;

        int direction = 0;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1]) {
                if(direction == 0)
                    direction = 1;
                else if(direction == 2)
                    return false;
            }
            else if(nums[i] < nums[i - 1]) {
                if(direction == 0)
                    direction = 2;
                else if(direction == 1)
                    return false;
            }
        }

        return true;
    }
};