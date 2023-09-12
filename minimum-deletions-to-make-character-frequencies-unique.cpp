class Solution {
public:
    unordered_map<char, int> m;
    unordered_set<int> frequencies;
    int count;
    int minDeletions(string s) {
        for(char c : s)
            m[c]++;

        for(auto k : m) {
            int frequency = k.second;

            while(frequency > 0 && frequencies.find(frequency) != frequencies.end()) {
                frequency--;
                count++;
            }

            frequencies.insert(frequency);
        }

        return count;
    }
};