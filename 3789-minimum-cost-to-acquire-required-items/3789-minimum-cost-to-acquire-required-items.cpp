class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long ans = 0;

        // Option 1: Buy both items together
        int common = min(need1, need2);

        ans += (long long)common * min(costBoth, cost1 + cost2);

        // Remaining requirement of item 1
        need1 -= common;

        // Remaining requirement of item 2
        need2 -= common;

        // Buy remaining items individually or using both-type item
        ans += (long long)need1 * min(cost1, costBoth);
        ans += (long long)need2 * min(cost2, costBoth);

        return ans;
    }
};