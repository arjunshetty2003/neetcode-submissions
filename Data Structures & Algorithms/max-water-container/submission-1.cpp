class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int maxLeft = 0;
        int maxRight = 0;

        int maxArea = 0;

        while (left < right) {
            maxLeft = max(maxLeft, heights[left]);
            maxRight = max(maxRight, heights[right]);

            maxArea = max(maxArea, min(maxLeft, maxRight) * (right - left));

            if (maxLeft <= maxRight) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxArea;
    }
};
