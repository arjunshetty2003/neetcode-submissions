class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int lastEnd = result.back()[1];
            if (start <= lastEnd) {
                result.back()[1] = max(end, lastEnd);
            }
            else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
