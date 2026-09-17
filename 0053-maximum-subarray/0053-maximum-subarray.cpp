class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0;
        for (int x : nums) {
            sum += x;
            maxSum = max(sum, maxSum);
            if (sum < 0)
                sum = 0;
        }
        return maxSum;
    }
};