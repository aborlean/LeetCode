class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n;
        vector<int> aux1(text2.length() + 1, 0);
        vector<int> aux2(text2.length() + 1, 0);

        for(int i = text1.length() - 1; i >= 0; i--) {
            for(int j = text2.length() - 1; j >= 0; j--) {
                if(text1[i] == text2[j])
                    n = 1 + aux2[j + 1];
                else
                    n = max(aux1[j + 1], aux2[j]);
                aux1[j] = n;
            }
            aux2 = aux1;
        }
        return aux2[0];
    }
};