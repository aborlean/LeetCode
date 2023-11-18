class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;

        unordered_map<int, vector<int>> stops;
        for(int i = 0; i < routes.size(); i++)
            for(int stop : routes[i])
                stops[stop].push_back(i);

        vector<int> vis(routes.size(), 0);
        queue<int> q;
        q.push(source);
        int count = 0;

        while(!q.empty()) {
            int aux = q.size();
            while(aux--) {
                int stop = q.front();
                q.pop();
                if(stop == target)
                    return count;
                for(auto x : stops[stop]) {
                    if(vis[x])
                        continue;
                    vis[x] = 1;
                    for(auto y : routes[x])
                        q.push(y);
                }
            }
            count++;
        }

        return -1;
    }
};