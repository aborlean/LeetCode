class Solution {
public:
    int indegree[50001];
    unordered_map<int, vector<int>> g;
    vector<int> distance;
    queue<int> q;

    void build_graph(vector<vector<int>>& relations) {
        for(auto x : relations) {
            g[x[0] - 1].push_back(x[1] - 1);
            indegree[x[1] - 1]++;
        }
    }


    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        build_graph(relations);

        distance = time;

        for(int i = 0; i < n; i++)
            if(indegree[i] == 0)
                q.push(i);

        while(!q.empty()) {
            int k = q.front();
            q.pop();

            for(auto x : g[k]) {
                distance[x] = max(distance[x], distance[k] + time[x]);
                indegree[x]--;

                if(indegree[x] == 0)
                    q.push(x);
            }
        }

        int ma = -1;
        for(int x : distance)
            ma = max(ma, x);

        return ma;
    }
};