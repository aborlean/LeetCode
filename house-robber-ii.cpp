class Solution {
public:

    int sum(vector<int>& nums, int start, int finish) {
        int first = 0, second = 0;

        for(int i = start; i <= finish; i++) {
            int aux = max(first + nums[i], second);
            first = second;
            second = aux;
        }

        return second;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        return max(sum(nums, 0, nums.size() - 2), sum(nums, 1, nums.size() - 1));
    }
};