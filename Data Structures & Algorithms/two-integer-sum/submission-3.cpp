class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> numIndex;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (! numIndex.count(target - nums[i])) {
                numIndex[nums[i]] = i;
            }
            else {
                return {numIndex[target - nums[i]], i};
            }
        }

        return {};        
    }
};
