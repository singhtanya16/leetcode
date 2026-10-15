class Solution {
public:
void nextPermutation(vector<int>& nums) {
int n = nums.size();
int index = -1;
    // Step 1: Find the pivot
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            index = i;
            break;
        }
    }

    // Step 2: Swap pivot with the next greater element
    if (index != -1) {
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
    }

    // Step 3: Reverse the suffix
    reverse(nums.begin() + index + 1, nums.end());
}

};
