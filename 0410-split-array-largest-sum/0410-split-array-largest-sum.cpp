class Solution {
public:
    pair<int, int> maxSum(vector<int>& nums) {
        int sum = 0;
        int maxV = nums[0];
        for (int x : nums) {
            sum += x;
            maxV = max(maxV, x);
        }
        return {maxV, sum};
    }
    bool canBeSplitInKPartion(vector<int>& nums, int val, int k) {
        int noPartions = 1;
        int sum = 0;
        for (int x : nums) {
            if (sum + x > val) {
                noPartions++;
                sum = x;
                if (noPartions > k) {
                    return false;
                }
            } else {
                sum += x;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = maxSum(nums).first;
        int high = maxSum(nums).second;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canBeSplitInKPartion(nums, mid, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};