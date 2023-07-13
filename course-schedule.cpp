class Solution {
public:
    unordered_map<int, set<int>> g;
    set<int> seen;
    vector<bool> visited;

    void new_edge(int a, int b) {
        g[a].insert(b);
    }

    bool cycle(int course) {
        if(seen.find(course) != seen.end())
            return false;

        seen.insert(course);
        visited[course] = true;

        for(int value : g[course])
            if(visited[value] || cycle(value))
                return true;

        visited[course] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; i++)
            visited.push_back(false);

        for(int i = 0; i < prerequisites.size(); i++)
            new_edge(prerequisites[i][0], prerequisites[i][1]);

        for(int i = 0; i < numCourses; i++)
            if(cycle(i))
                return false;

        return true;
    }
};