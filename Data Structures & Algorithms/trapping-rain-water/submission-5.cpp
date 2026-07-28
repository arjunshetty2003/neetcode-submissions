class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int area = 0;

        int maxLeft = height[0];
        int maxRight = height[height.size()-1];

        while (left < right) {
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);

            if (maxLeft <= maxRight) {
                area += maxLeft - height[left];
                left++;
            }
            else {
                area += maxRight - height[right];
                right--;
            }
        }
        return area;
    }
};
