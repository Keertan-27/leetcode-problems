class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], sum = 0;
        for (int x : nums) {
            if (sum < 0)
                sum = 0;
            sum += x;
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};