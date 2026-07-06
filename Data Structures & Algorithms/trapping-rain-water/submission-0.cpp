class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxValue = 0;

        int maxLeft = height[left];
        int maxRight = height[right];

        while (left < right) {
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);

            if (maxLeft <= maxRight) {
                if (maxLeft - height[left] > 0)
                   maxValue += maxLeft - height[left];
                left++;
            }

            else {
                if (maxRight - height[right] > 0)
                   maxValue += maxRight - height[right];
                right--;
            }
        }

        return maxValue;
    }
};
