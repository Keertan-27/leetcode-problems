class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        string pref = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string word = strs[i];
            int j = 0;
            while (j < pref.size() && j < word.size() && pref[j] == word[j]) {
                j++;
            }
            pref = pref.substr(0, j);
        }
        return pref;
    }
};