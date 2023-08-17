class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i = 0; i <= n; i++) {
            int s = 0, x = i;

            while(x) {
                s += x % 2;
                x /= 2;
            }

            ans.push_back(s);
        }

        return ans;
    }
};