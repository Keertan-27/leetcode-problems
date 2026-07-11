class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int piviot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                piviot = i;
                break;
            }
        }

        if (piviot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > piviot; i--) {
            if (nums[i] > nums[piviot]) {
                swap(nums[i], nums[piviot]);
                break;
            }
        }

        reverse(nums.begin() + piviot + 1, nums.end());
    }
};