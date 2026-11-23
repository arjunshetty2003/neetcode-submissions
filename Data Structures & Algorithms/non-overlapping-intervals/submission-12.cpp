class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int prevClose = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (prevClose > intervals[i][0]) {
                count++;
                prevClose = min(prevClose, intervals[i][1]);
            }
            else {
                prevClose = intervals[i][1];
            }
        }
        return count;
    }
};
