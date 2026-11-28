class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        // Step 1: Count frequency of factors
        for (auto &it : items) {
            freq[it[0]]++;
            minPrice = min(minPrice, it[1]);
        }

        // Step 2: Count multiples of every factor
        vector<int> cnt(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }
            cnt[i]--;
        }

        // Step 3: Store profitable bonus purchases
        vector<pair<int, int>> v;

        for (auto &it : items) {

            int factor = it[0];
            int price = it[1];

            if (cnt[factor] > 0 && price < 2LL * minPrice) {
                v.push_back({price, cnt[factor]});
            }
        }

        // Step 4: Sort by price
        sort(v.begin(), v.end());

        long long ans = 0;
        long long remaining = budget;

        // Step 5: Greedily purchase bonus items
        for (auto &it : v) {

            long long price = it.first;
            long long count = it.second;

            long long buy = min(count, remaining / price);

            ans += buy * 2;
            remaining -= buy * price;
        }

        // Step 6: Buy cheapest items with remaining budget
        ans += remaining / minPrice;

        return (int)ans;
    }
};