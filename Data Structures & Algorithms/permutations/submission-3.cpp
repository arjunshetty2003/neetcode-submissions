class Solution {
    vector<vector<int>> perm;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        p(nums, 0);
        return perm;
    }
    void p(vector<int>&nums, int idx) {
        if (idx == nums.size()) {
            perm.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            p(nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }
};
