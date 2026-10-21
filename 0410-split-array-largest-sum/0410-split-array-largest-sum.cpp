class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size() ;
        int low= *max_element(nums.begin() , nums.end());
        int high= accumulate(nums.begin(), nums.end(), 0);
        while (low<=high){
            int mid= low+(high-low)/2 ;
            int sum=0 ;
            int arr=1 ;
            for (int i=0 ; i<n ; i++){
                if (sum+nums[i]<=mid){
                    sum+=nums[i] ;
                }
                else{
                    arr++ ;
                    sum= nums[i];
                }
            }
            if (arr<=k){
                high= mid-1 ;
            }
            else {
                low = mid+1 ;
            }
        }
        return low ;
    }
};