class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        // Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<int> last(26, -1);

        // DFS to find nearest ancestor with same character
        function<void(int)> dfs = [&](int node) {
            int ch = s[node] - 'a';

            int previous = last[ch];

            if (node == 0 || previous == -1) {
                newParent[node] = parent[node];
            } else {
                newParent[node] = previous;
            }

            last[ch] = node;

            for (int child : adj[node]) {
                dfs(child);
            }

            last[ch] = previous;
        };

        dfs(0);

        // Build modified tree
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        // Calculate subtree sizes
        function<int(int)> calculate = [&](int node) {
            for (int child : tree[node]) {
                ans[node] += calculate(child);
            }

            return ans[node];
        };

        calculate(0);

        return ans;
    }
};