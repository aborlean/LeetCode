class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m;

        for(int x : nums) {
            int aux = x - reverse(x);
            if(m.find(aux) != m.end())
                m[aux]++;
            else
                m[aux] = 1;
        }

        long long ans = 0;
        int mod = 1000000007;

        for(auto x : m)
            ans = (ans % mod + (1LL * x.second * (1LL * x.second - 1) / 2)) % mod;

        return (int)ans;
    }
};