class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2) {
        return v1[1] < v2[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int k = 0, ans = 1;
        sort(pairs.begin(), pairs.end(), cmp);
        for(int i = 1; i < pairs.size(); i++)
            if(pairs[k][1] < pairs[i][0]) {
                k = i;
                ans++;
            }

        return ans;
    }
};