class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int sum = 0;
        int maxLeft = height[left];
        int maxRight = height[right];
        while (left < right) {
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);

            if (maxLeft <= maxRight) {
                sum += maxLeft - height[left];
                left++;
            }
            else {
                sum += maxRight - height[right];
                right--;
            }
        }

        return sum;
    }
};
