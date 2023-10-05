class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int i = 0;
        long long size = 0;

        while(size < k) {
            if(isdigit(s[i]))
                size *= s[i] - '0';
            else
                size++;
            i++;
        }

        for(int j = i - 1; j >= 0; j--) {
            if(isdigit(s[j])) {
                size /= s[j] - '0';
                k %= size;
            }
            else {
                if(k == 0 || k == size)
                    return string(1, s[j]);
                 size--;
            }
        }

        return "";
    }
};