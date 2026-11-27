class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int minSpeed = r;
        while (l <= r) {
            int k = (l + r) / 2;
            long long totalTime = 0;
            for (int pile : piles) {
                totalTime += ceil(static_cast<double> (pile) / k);
            }
            if (totalTime <= h) {
                minSpeed = k;
                r = k - 1;
            }
            else {
                l = k + 1;
            }
        }
        return minSpeed;
    }
};
