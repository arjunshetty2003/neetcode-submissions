class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long, int> mp;
        long long prefixSum = 0;
        mp[prefixSum] = 1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];

            if (mp.count(prefixSum - k)) {
                count += mp[prefixSum - k];
            }

            mp[prefixSum]++;
        }

        return count;
    }
};