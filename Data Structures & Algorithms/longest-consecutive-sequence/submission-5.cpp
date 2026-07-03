class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sets;
        vector<int> reference;
        for (int num : nums) {
            if (sets.count(num) == false) {
                reference.push_back(num);
                sets.insert(num);
            }
        }

        sort(reference.begin(), reference.end());
        int max_subsequence = 0;
        int n = reference.size();
        int i = 0;
        while (i < n) {
            int subsequence_len = 1;
            while (i + 1 < n && reference[i+1] == 1 + reference[i] ) {
                subsequence_len++;
                i++;
            }
            max_subsequence = max(max_subsequence, subsequence_len);
            i++;
        }
        return max_subsequence ;
    }
};
