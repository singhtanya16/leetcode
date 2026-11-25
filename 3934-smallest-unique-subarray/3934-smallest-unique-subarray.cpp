class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 1;

        // Coordinate compression
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<int> rank(n);

        for (int i = 0; i < n; i++) {
            rank[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();
        }

        // Build Suffix Array
        vector<int> sa(n);
        iota(sa.begin(), sa.end(), 0);

        for (int k = 1; k < n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;

                return ra < rb;
            });

            vector<int> newRank(n);
            newRank[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                bool different = rank[a] != rank[b];

                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;

                if (ra != rb) different = true;

                newRank[b] = newRank[a] + different;
            }

            rank = newRank;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Build LCP Array using Kasai's Algorithm
        vector<int> pos(n), lcp(n, 0);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            if (r == 0) continue;

            int j = sa[r - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;

            if (h > 0) h--;
        }

        // Find minimum unique subarray length
        int ans = n;

        for (int i = 0; i < n; i++) {
            int maxLCP = lcp[i];

            if (i + 1 < n)
                maxLCP = max(maxLCP, lcp[i + 1]);

            if (maxLCP < n - sa[i]) {
                ans = min(ans, maxLCP + 1);
            }
        }

        return ans;
    }
};