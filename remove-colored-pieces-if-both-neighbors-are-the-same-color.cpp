class Solution {
public:
    bool winnerOfGame(string colors) {
        map<char, int> m;

        for(auto i = colors.begin(); i != colors.end(); ) {
            char x = *i;
            auto t = i;
            while(t != colors.end() && *t == x)
                t++;
            m[x] += max(int(distance(i, t) - 2), 0);
            i = t;
        }

        if(m['A'] > m['B'])
            return true;
        return false;
    }
};