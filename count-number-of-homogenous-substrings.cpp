class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0;
        int p = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[p] == s[i]) {
                ans += i - p + 1;
            }
            else {
                ans++;
                p = i;
            }
        }

        return (int)(ans % 1000000007);
    }
};