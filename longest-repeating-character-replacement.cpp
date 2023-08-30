class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), i = 0, j = 0, ma = 0, ans = -1;
        unordered_map<char, int> map;
        while(j < n) {
            map[s[j]]++;
            ma = max(ma, map[s[j]]);
            int current = j - i + 1;
            if(current - ma > k) {
                map[s[i]]--;
                i++;
            }
            current = j - i + 1;
            ans = max(ans, current);
            j++;
        }

        return ans;
    }
};