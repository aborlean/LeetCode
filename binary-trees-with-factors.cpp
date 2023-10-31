class Solution {
public:
    const int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<long long, long long> dp;

        for(int x : arr)
            dp[x] = 1;

        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < i; j++)
                if(arr[i] % arr[j] == 0 && dp[arr[i] / arr[j]]) {
                    dp[arr[i]] += (dp[arr[j]] * dp[arr[i] / arr[j]]) % mod;
                    dp[arr[i]] %= mod;
                }
        }

        int count = 0;
        for(auto x : dp) {
            count += x.second;
            count %= mod;
        }

        return count;
    }
};