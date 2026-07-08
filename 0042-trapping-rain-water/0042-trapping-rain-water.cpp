class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        int lmax = 0, rmax = 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] < lmax) {
                    total += lmax - height[left];
                } else {
                    lmax = height[left];
                }
                left++;
            } else {
                if (height[right] < rmax) {
                    total += rmax - height[right];
                } else {
                    rmax = height[right];
                }
                right--;
            }
        }
        return total;
    }
};