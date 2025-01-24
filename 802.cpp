

    bool func(vector<vector<int>>& graph, int i, vector<int>& state) {
        if (state[i] != 0) {
            // If node is already visited, return whether it's safe or not
            return state[i] == 2;
        }

        // Mark the node as being processed
        state[i] = 1;

        // Process all neighbors
        for (auto it : graph[i]) {
            if (!func(graph, it, state)) {
                // If any neighbor is not safe, this node is not safe
                return false;
            }
        }

        // Mark the node as safe
        state[i] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); // 0 = unvisited, 1 = processing, 2 = safe
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (func(graph, i, state)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
