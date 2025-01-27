class Solution {
public:
    void func(int target, int i, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp); // Valid combination found
            return;
        }
        if (i == candidates.size()) {
            return; // Exhausted all candidates
        }

        // Skip the current candidate
        func(target, i + 1, candidates, ans, temp);

        // Include the current candidate if it does not exceed the target
        if (candidates[i] <= target) {
            temp.push_back(candidates[i]); // Add candidate to current combination
            func(target - candidates[i], i, candidates, ans, temp); // Recur with reduced target
            temp.pop_back(); // Backtrack to explore other possibilities
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(target, 0, candidates, ans, temp);
        return ans;
    }
};
