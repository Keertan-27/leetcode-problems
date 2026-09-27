class Solution {
public:
    int sumV(vector<int>& nums) {
        int maxElm = 0;
        for (int x : nums) {
            maxElm = max(maxElm, x);
        }
        return maxElm;
    }
    bool lessThanThreshold(vector<int>& nums, int val, int threshold) {
        int divSum = 0;
        for (int x : nums) {
            divSum += (x + val - 1) / val;
            if (divSum > threshold) {
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1, high = sumV(nums);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (lessThanThreshold(nums, mid, threshold)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};