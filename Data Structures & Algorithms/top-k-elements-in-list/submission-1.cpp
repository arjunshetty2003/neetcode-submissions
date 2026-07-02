class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> numCount;

        for (int num : nums) {
            numCount[num]++;
        }

        vector<vector<int>> freq(nums.size() + 1);

        for (auto &entry : numCount) {
            freq[entry.second].push_back(entry.first);
        }

        int n = freq.size() - 1;

        while (n >= 1 && k > 0) {
            for (int num : freq[n]) {
                result.push_back(num);
                k--;
            }
            
            if (k == 0) {
                break;
            }
            n--;
        }

        return result;
    }
};
