class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int loot_2 = 0;
        int loot_1 = 0;
        for (int i = 0; i < n - 1; i++) {
            int temp = max(loot_2 + nums[i], loot_1);
            loot_2 = loot_1;
            loot_1 = temp;
        }

        int clockwise = loot_1;

        loot_2 = loot_1 = 0;
        for (int i = n - 1; i >= 1; i--) {
            int temp = max(loot_2 + nums[i], loot_1);
            loot_2 = loot_1;
            loot_1 = temp;
        }

        int anticlockwise = loot_1;

        return max(clockwise, anticlockwise);
    }
};
