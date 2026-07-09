class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAar = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left <= right) {
            if (height[left] <= height[right]) {
                maxAar = max(maxAar, (right - left) * height[left]);
                left++;
            } else {
                maxAar = max(maxAar, (right - left) * height[right]);
                right--;
            }
        }
        return maxAar;
    }
};