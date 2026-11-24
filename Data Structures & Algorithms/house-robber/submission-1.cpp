class Solution {
public:
    int rob(vector<int>& nums) {
        int loot_2 = 0;
        int loot_1 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int temp = max(loot_2 + nums[i], loot_1);
            loot_2 = loot_1;
            loot_1 = temp;
        }

        return loot_1;
    }
};
