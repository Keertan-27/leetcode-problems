class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int nSwap = 0;
        while (i <= j) {
            if (nums[j] == 0)
                j--;
            else if (nums[i] == 0) {
                swap(nums[i], nums[j]);
                nSwap++;
                i++;
                j--;
            } else {
                i++;
            }
        }
        return nSwap;
    }
};