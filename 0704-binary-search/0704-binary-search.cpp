class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid;
        // No need for iteration using for loop . If the target isn't found, the while loop eventually ends. The outer for loop then repeats, even though the search is already complete.
            while (low <= high) {
                mid = (low + high) / 2;

                if (nums[mid] == target) {
                    return mid;
                } else if (target > nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
     

        return -1;
    }
};