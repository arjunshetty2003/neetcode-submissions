class Solution {
public:
    int climbStairs(int n) {
        
        int curr_2 = 1;
        int curr_1 = 1;
        for (int i = n - 2; i >= 0; i--) {
            int curr = curr_2 + curr_1;
            curr_2 = curr_1;
            curr_1 = curr;
        }
        return curr_1;
    }
};
