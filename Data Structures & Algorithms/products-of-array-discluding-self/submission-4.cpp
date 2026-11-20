class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prod(n);
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            prod[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            prod[i] *= suffix;
            suffix *= nums[i];
        }

        return prod;
    }
};
