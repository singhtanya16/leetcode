class Solution {
   public:
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {  // array has only 1 element
            return nums[0];
        }
        if (nums[0] != nums[1]) {    //if first element of arr is single element 
        return nums[0];
        }
        if (nums[n - 1] != nums[n - 2]) {  // if last element of arr is single element
            return nums[n - 1];
        }
        // for remaining elements i.e from nums[1] to nums[n] .
        int low = 1;
        int high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {  // if mid is single element
                return nums[mid];
            }
            // elimination : 
            // we are on left half
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1])        // we r at odd index on left side 
                || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) { // we r at even index on left side
                    low = mid + 1; 
                }
            // we r on right half
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
    };