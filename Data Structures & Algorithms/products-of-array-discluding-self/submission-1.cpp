class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                prod *= nums[j];
            }
            result.push_back(prod);
        }
        return result;
    }
};
