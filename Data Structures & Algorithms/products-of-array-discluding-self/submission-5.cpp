class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prodArray(n);
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            prodArray[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            prodArray[i] *= suffix;
            suffix *= nums[i];
        }

        return prodArray;
    }
};
