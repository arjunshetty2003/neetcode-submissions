class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        unordered_map<int, int> freqCounter;

        for (int i : nums) {
            freqCounter[i]++;
        } 

        vector<vector<int>> freqMap(n + 1);

        for (auto &entry : freqCounter) {
            freqMap[entry.second].push_back(entry.first);
        }

        for (int i = n; i >= 0; i--) {
            if (!freqMap[i].empty()) {
                for (int num : freqMap[i]) {
                    result.push_back(num);
                    k--;
                }
            }
            if (k == 0)
               break;
        }

        return result;
    }
};
