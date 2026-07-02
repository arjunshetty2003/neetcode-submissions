class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<pair<int, int>> maps;
        for (auto &entry : freq) {
            maps.push_back({entry.second, entry.first});
        }
        sort(maps.begin(), maps.end());
        int n = maps.size() - 1;
        while (k > 0) {
            auto entry = maps[n];
            result.push_back(entry.second);
            n--;
            k--;
        }
        return result;
    }
};
