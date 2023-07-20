class Solution {
public:

    unordered_map<int, int> m;
    int maximum = 0;

    int longestSubsequence(vector<int>& arr, int difference) {

        for(int i = 0; i < arr.size(); i++) {
            if(m.find(arr[i] - difference) != m.end())
                m[arr[i]] = m[arr[i] - difference] + 1;
            else
                m[arr[i]] = 1;
            maximum = max(maximum, m[arr[i]]);
        }

        return maximum;
    }
};