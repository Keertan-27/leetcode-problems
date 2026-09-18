class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elm = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (cnt == 0) {
                elm = nums[i];
            }
            if (nums[i] != elm) {
                cnt--;
            } else {
                cnt++;
            }
        }
        return elm;
    }
};