class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int elm1 = 0, elm2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && elm2 != nums[i]) {
                elm1 = nums[i];
                cnt1++;
            } else if (cnt2 == 0 && elm1 != nums[i]) {
                elm2 = nums[i];
                cnt2++;
            } else if (nums[i] == elm1)
                cnt1++;
            else if (nums[i] == elm2)
                cnt2++;
            else {
                cnt1--, cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (int x : nums) {
            if (x == elm1) {
                cnt1++;
            } else if (x == elm2) {
                cnt2++;
            }
        }

        vector<int> ans;
        if (cnt1 > n / 3) {
            ans.push_back(elm1);
        }
        if (cnt2 > n / 3) {
            ans.push_back(elm2);
        }
        return ans;
    }
};