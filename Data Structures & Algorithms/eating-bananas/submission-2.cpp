class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxRate = *max_element(piles.begin(), piles.end());
        int minRate = 1;
        
        int k = maxRate;

        while (minRate <= maxRate) {
            int midRate = minRate + (maxRate - minRate) / 2;
            int sumHours = 0;
            for (int pile : piles) {
                sumHours += ceil((double) pile / midRate);
            }

            if (sumHours <= h) {
                k = midRate;
                maxRate = midRate - 1;
            }
            else {
                minRate = midRate + 1;
            }
        }

        return k;
    }
};
