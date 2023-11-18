class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        long long current = 0;

        for(int left = 0, right = 0; right < nums.size(); right++) {
            current += nums[right];

            while(current + k < 1LL * nums[right] * (right - left + 1)) {
                current -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};