class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            seen.insert(num);
        }
        int maximumCount = 0;
        for (int num : nums) {
            if (seen.count(num - 1)) {
                continue;
            }
            else {
                int count = 0;
                int n = num;
                while (seen.count(n)) {
                    count++;
                    n++;
                }
                maximumCount = max(maximumCount, count);
            }
        }
        return maximumCount;
    }
};
