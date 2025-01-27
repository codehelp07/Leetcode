class Solution {
public:
//DFS with Memoization
    bool dfs(int u, int v, vector<vector<int>>& adj, vector<vector<int>>& memo) {
        if (memo[u][v] != -1) return memo[u][v];
        
        for (int neighbor : adj[u]) {
            if (neighbor == v || dfs(neighbor, v, adj, memo)) {
                return memo[u][v] = true;
            }
        }
        return memo[u][v] = false;
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<vector<int>> memo(numCourses, vector<int>(numCourses, -1)); // -1 means not computed
        
        // Build the adjacency list
        for (const auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }
        
        // Answer each query using DFS with memoization
        vector<bool> ans;
        for (const auto& query : queries) {
            ans.push_back(dfs(query[0], query[1], adj, memo));
        }
        return ans;
    }
};


//TLE
class Solution {
public:
    bool func(vector<vector<int>>adj,int pre,int task,vector<int>visited){
        visited[pre]=1;
        for(auto it:adj[pre]){
            if(it==task)return true;
            if(visited[it]==0){
                if(func(adj,it,task,visited))return true;
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();++i){
            //int pre=prerequisites[i][0];
            //int task =prerequisites[i][1]
            //(0 1)
            //0-->1 
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool>ans;
       
        for(int i=0;i<queries.size();++i){
            int pre=queries[i][0];
            int task=queries[i][1];
            vector<int> visited(numCourses, 0);
            ans.push_back(func(adj,pre,task,visited));
        }
        return ans;
    }
};

//Floyd-Warshall


class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        // Populate direct prerequisites
        for (const auto& pre : prerequisites) {
            reachable[pre[0]][pre[1]] = true;
        }

        // Compute transitive closure (Floyd-Warshall)
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    if (reachable[i][k] && reachable[k][j]) {
                        reachable[i][j] = true;
                    }
                }
            }
        }

        // Answer queries
        vector<bool> ans;
        for (const auto& query : queries) {
            ans.push_back(reachable[query[0]][query[1]]);
        }
        return ans;
    }
};
