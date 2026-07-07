class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores INDICES, values decreasing front to back
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // remove indices that fell out of the window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // remove smaller elements from back — they can never be
            // the max while nums[i] is still in the window
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // window is full once i >= k - 1
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
