class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        bool started = false;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                started = true;
                cnt++;
            } else if (started == true)
                break;
        }
        return cnt;
    }
};