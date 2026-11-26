class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int prevClose = result.back()[1];
        for (int i = 1; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (prevClose < start) {
                result.push_back(intervals[i]);
                prevClose = intervals[i][1];
            }
            else {
                prevClose = max(prevClose, end);
                result.back()[1] = prevClose;
            }
        }
        return result;
    }
};
