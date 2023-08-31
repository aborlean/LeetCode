class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber > 0) {
            columnNumber--;
            char c = 'A' + (columnNumber % 26);
            ans = c + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};