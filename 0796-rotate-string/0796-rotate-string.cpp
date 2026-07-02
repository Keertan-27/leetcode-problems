class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        string doub = s + s;
        return doub.find(goal) != string::npos;
    }
};