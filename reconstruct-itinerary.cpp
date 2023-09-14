class Solution {
public:
    unordered_map<string, vector<string>> graph;
    vector<string> itinerary;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i = 0; i < tickets.size(); i++)
            graph[tickets[i][0]].push_back(tickets[i][1]);

        for(auto &i : graph)
            sort(i.second.rbegin(), i.second.rend());

        stack<string> st;
        st.push("JFK");

        while(!st.empty()) {
            string current = st.top();

            vector<string> &destinations = graph[current];

            if(!destinations.empty()) {
                string next = destinations.back();
                destinations.pop_back();
                st.push(next);
            }
            else {
                itinerary.push_back(current);
                st.pop();
            }
        }

        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};