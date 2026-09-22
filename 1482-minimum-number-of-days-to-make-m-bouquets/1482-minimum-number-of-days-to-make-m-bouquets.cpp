class Solution {
public:
    pair<int, int> minMaxVal(vector<int>& bloomDay) {
        int minV = INT_MAX;
        int maxV = INT_MIN;
        for (int x : bloomDay) {
            minV = min(minV, x);
            maxV = max(maxV, x);
        }
        return {minV, maxV};
    }
    bool willBloom(vector<int>& bloomDay, int val, int m, int k) {
        int days = k;
        for (int x : bloomDay) {
            if (x <= val) {
                days--;
                if (days == 0) {
                    m--;
                    days = k;
                }
            } else {
                days = k;
            }
            if (m == 0) {
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long minN = 1LL * m * k;
        if (n < minN)
            return -1;
        int low = minMaxVal(bloomDay).first;
        int high = minMaxVal(bloomDay).second;
        while (low <= high) {
            int mid = (low + high) / 2;
            bool bloomed = willBloom(bloomDay, mid, m, k);
            if (bloomed) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};