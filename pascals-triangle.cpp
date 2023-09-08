class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int i = 1;

        vector<int> v;
        v.push_back(1);
        ans.push_back(v);
        numRows--;

        while(numRows) {
            vector<int> v;
            v.push_back(1);
            for(int k = 0; k < i - 1; k++)
                v.push_back(ans[i - 1][k] + ans[i - 1][k + 1]);
            v.push_back(1);
            ans.push_back(v);
            i++;
            numRows--;
        }

        return ans;
    }
};