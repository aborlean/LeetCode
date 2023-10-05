class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;

        for(int i: nums)
            sum += i;

        int ma = -1, current = 0;

        for(int left = 0, right = 0; right < nums.size(); right++) {
            current += nums[right];
            while(left <= right && current > sum - x)
                current -= nums[left++];
            if(current == sum - x)
                ma = max(ma, right - left + 1);
        }

        if(ma == -1)
            return  ma;
        return nums.size() - ma;
    }
};