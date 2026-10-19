class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size() ;
        int low = *min_element(bloomDay.begin() , bloomDay.end());
        int high= *max_element(bloomDay.begin() , bloomDay.end());
        if ((long long) m *k > n ){
            return -1 ;
        }
        while (low<=high){
            int mid= low+(high-low)/2 ;
            int cnt=0 ;
            int boquet=0 ;
            for (int i=0 ; i<n ; i++){
                if (bloomDay[i] <= mid){
                    cnt++ ;
                if (cnt==k){
                    boquet++ ;
                    cnt=0;
                }
            }
            else {
                cnt=0 ;
            }

        }
        if (boquet >=m){
            high= mid-1 ;
        }
        else{
            low = mid+1;
        }
        }
        return low ;
        
    }
};