class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int left = 0;
        int right = k - 1;
        int n = nums.size();
        while (right < n) {
            auto maxEle = max_element(nums.begin() + left, nums.begin() + right + 1);
            result.push_back(*maxEle);
            left++;
            right++;
        }
        return result;
    }
};
