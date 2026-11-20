class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxLen = 0;
        for (int x : seen) {
            if (!seen.count(x - 1)) {
                int count = 1;
                int current = x;

                while(seen.count(current + 1)) {
                    count++;
                    current++;
                }

                maxLen = max(maxLen, count);
            }
        }
        return maxLen;
    }
};
