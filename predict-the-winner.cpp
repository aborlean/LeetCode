class Solution {
public:
    int back(int left, int right, int count, bool first, vector<int>& nums) {
        if(count == 0)
            return 0;
        if(first) {
            int val1 = nums[left] + back(left + 1, right, count - 1, false, nums);
            int val2 = nums[right] + back(left, right - 1, count - 1, false, nums);
            return max(val1, val2);
        }
        else {
            int val1 = -nums[left] + back(left + 1, right, count - 1, true, nums);
            int val2 = -nums[right] + back(left, right - 1, count - 1, true, nums);
            return min(val1, val2);
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        int count = nums.size();
        int sum = 0;

        for(int i = 0; i < count; i++)
            sum += nums[i];

        int val = back(0, count - 1, count, true, nums);
        return val >= 0;
    }
};