class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestCnt = 0;
        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }
        for (int it : st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int elm = it;
                while (st.find(elm + 1) != st.end()) {
                    cnt++;
                    elm++;
                }
                longestCnt = max(longestCnt, cnt);
            }
        }
        return longestCnt;
    }
};