class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet = {{}};
        for (int num : nums) {
            int size = powerSet.size();
            for (int i = 0; i < size; i++) {
                vector<int> sets = powerSet[i];
                sets.push_back(num);
                powerSet.push_back(sets);
            }
        }
        return powerSet;
    }
};
