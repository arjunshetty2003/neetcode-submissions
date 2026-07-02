class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diffIndex;

        for (int i = 0; i < nums.size(); i++) {
            if (!diffIndex.count(nums[i])) {
                diffIndex[target - nums[i]] = i;
            }
            else {
                return {diffIndex[nums[i]], i};
            }
        }
        return {};
    }
};
