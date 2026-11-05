class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diffMap;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (diffMap.count(target - nums[i]) == false)
                diffMap[nums[i]] = i;
            else
                return {diffMap[target - nums[i]], i};
        }
        return {-1, -1};
    }
};
