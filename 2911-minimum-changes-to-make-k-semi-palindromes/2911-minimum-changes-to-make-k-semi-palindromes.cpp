class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        // cost[i][j] = minimum changes to make s[i...j]
        // a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                cost[i][j] = INT_MAX;

                // Find proper divisors of length
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    // Check each sequence with gap d
                    for (int r = 0; r < d; r++) {
                        int left = i + r;
                        int right = i + r + ((len - 1 - r) / d) * d;

                        while (left < right) {
                            if (s[left] != s[right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // DP
        const int INF = 1e9;

        vector<vector<int>> dp(k + 1,
                               vector<int>(n + 1, INF));

        dp[0][0] = 0;

        for (int groups = 1; groups <= k; groups++) {
            for (int i = 2 * groups; i <= n; i++) {

                for (int j = 2 * (groups - 1); j <= i - 2; j++) {

                    if (dp[groups - 1][j] == INF)
                        continue;

                    dp[groups][i] = min(
                        dp[groups][i],
                        dp[groups - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};