class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mi = INT_MAX;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[left] <= nums[mid]) {
                mi = min(mi, nums[left]);
                left = mid + 1;
            }
            else {
                mi = min(mi, nums[mid]);
                right = mid - 1;
            }
        }

        return mi;
    }
};