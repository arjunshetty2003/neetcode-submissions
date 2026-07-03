class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            seen.insert(num);
        }
        int n = nums.size();
        int max_Subsequence = 0;
        for (int i = 0; i < n; i++) {
            if (!seen.count(nums[i] - 1)) {
                int count = 1;
                int ref = nums[i];
                while (seen.count(ref + 1)) {
                    count++;
                    ref++;
                }
                max_Subsequence = max(max_Subsequence, count);
            }
        }
        return max_Subsequence;
    }
};
