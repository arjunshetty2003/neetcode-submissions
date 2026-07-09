class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        // Sort indices by position descending
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return position[a] > position[b];
        });

        vector<double> stack; // stores arrival times of fleet "leaders"

        for (int i : idx) {
            double time = (double)(target - position[i]) / speed[i];
            if (stack.empty() || time > stack.back()) {
                stack.push_back(time);
            }
            // else: absorbed into fleet on top of stack, do nothing
        }

        return stack.size();
    }
};
