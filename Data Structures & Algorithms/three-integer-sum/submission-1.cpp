class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_set<string> seen;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> vec = {nums[i], nums[j], nums[k]};
                        sort(vec.begin(), vec.end());
                        string key = to_string(vec[0]) + "," + to_string(vec[1]) + "," + to_string(vec[2]);
                        if (!seen.count(key)) {
                            result.push_back(vec);
                            seen.insert(key);
                        }
                        else {
                            continue;
                        }
                    }
                }
            }
        }
        return result;
    }
};
