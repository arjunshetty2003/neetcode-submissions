class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            seen.insert(num);
        }

        int n = nums.size();
        int i = 0;
        int maxSequence = 0;
        while (i < n) {
            int ref = nums[i];
            int count = 1;
            while (seen.count(ref - 1)) {
                count++;
                ref--;
            }
            maxSequence = max(maxSequence, count);
            i++;
        }

        return maxSequence;
    }
};
