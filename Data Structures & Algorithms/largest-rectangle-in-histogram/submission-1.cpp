class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> stk;
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int start = i;
            while (!stk.empty() && stk.top().second > heights[i]) {
                int index = stk.top().first;
                int height = stk.top().second;

                maxArea = max(maxArea, height * (i - index));
                start = index;
                stk.pop();
            }

            stk.push({start, heights[i]});
        }

        while (!stk.empty()) {
            int index = stk.top().first;
            int height = stk.top().second;
            maxArea = max(maxArea, height * (n - index));
            stk.pop();
        }
        return maxArea;
    }
};
