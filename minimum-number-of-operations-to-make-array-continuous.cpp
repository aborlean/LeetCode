class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int result = n;

        sort(nums.begin(), nums.end());
        set<int> v(nums.begin(), nums.end());
        vector<int> s;

        for(auto x : v)
            s.push_back(x);

        for(int i = 0; i < s.size(); i++) {
            int left = i, right = s.size() - 1, target = s[i] + n - 1, pos = -1;
            while(left <= right) {
                int mid = (left + right) / 2;
                if(s[mid] <= target) {
                    left = mid + 1;
                    pos = mid + 1;
                }
                else
                    right = mid - 1;
            }

            result = min(result, n - pos + i);
        }
        return result;
    }
};