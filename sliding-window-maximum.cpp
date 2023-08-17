class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1);
        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < k; i++)
            pq.push({nums[i], i});

        ans[0] = pq.top().first;

        for(int i = k; i < nums.size(); i++) {
            while(!pq.empty() && pq.top().second <= i - k)
                pq.pop();
            pq.push({nums[i], i});
            ans[i - k + 1] = pq.top().first;
        }
        return ans;
    }
};