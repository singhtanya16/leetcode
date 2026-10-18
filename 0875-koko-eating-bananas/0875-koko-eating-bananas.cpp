class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1; //divisor will never be less than 1 , we cannot divide by 0
        int high = *max_element(piles.begin(), piles.end()); // take high at max element present in given array .
        int ans = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2; //take long long may be mid overflows .
            long long sum = 0; //take long long as may be sum gets overflow
            for (int i = 0; i < n; i++) {
                sum = sum + ceil(double(piles[i]) / mid);
            }
            if (sum <= h){
                ans = mid ;
                high = mid-1 ;
            }
            else {
                low = mid+1 ;
            }
        }
        return ans ;
    }
};