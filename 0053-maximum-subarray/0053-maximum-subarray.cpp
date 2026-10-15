class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size () ;
        long long sum = 0 ;
        long max = LONG_MIN ;
        for (int i=0 ; i<n ; i++){
            sum +=nums[i] ;
            if (sum>max){
                max = sum ;
            }
            if (sum < 0){
                sum = 0 ; 
            }
        }
        return max  ;
        
    }
};