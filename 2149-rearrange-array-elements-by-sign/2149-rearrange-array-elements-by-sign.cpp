class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int indPos = 0, indNeg = 1;
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans[indPos] = nums[i];
                indPos += 2;
            } else {
                ans[indNeg] = nums[i];
                indNeg += 2;
            }
        }
        return ans;
    }
};