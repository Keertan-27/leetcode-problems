class Solution {
public:
    pair<int, int> maxSumVal(vector<int>& weights) {
        int sumV = 0, maxV = weights[0];
        for (int x : weights) {
            maxV = max(maxV, x);
            sumV += x;
        }
        return {maxV, sumV};
    }
    bool daysToShipPackages(vector<int>& weights, int val, int days) {
        int sum = 0;
        int dayR = 0;
        for (int x : weights) {
            sum += x;
            if (sum > val) {
                dayR++;
                sum = x;
            }
            if (dayR > days) {
                return false;
            }
        }
        if (sum > 0) {
            dayR++;
        }
        return dayR <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = maxSumVal(weights).first;
        int high = maxSumVal(weights).second;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (daysToShipPackages(weights, mid, days)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};