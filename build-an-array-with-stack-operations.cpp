class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int p = 0;

        for(int i = 1; i <= n; i++) {
            if(p == target.size())
                break;
            ans.push_back("Push");
            if(i == target[p])
                p++;
            else
                ans.push_back("Pop");
        }

        return ans;
    }
};