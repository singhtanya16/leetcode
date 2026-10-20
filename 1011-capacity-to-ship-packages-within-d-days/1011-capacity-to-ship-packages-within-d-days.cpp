class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int total = 0;
            int countDays = 1;

            for (int i = 0; i < n; i++) {
                if (total + weights[i] <= mid) {
                    total += weights[i];
                }
                else {
                    countDays++;
                    total = weights[i];
                }
            }

            if (countDays <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};