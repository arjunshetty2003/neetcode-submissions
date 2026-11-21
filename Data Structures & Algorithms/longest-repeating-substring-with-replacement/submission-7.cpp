class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int n = s.length();
        unordered_map<int, int> freqCount;
        int maxValue = 0;
        int maxLen = 0;
        for (right; right < n; right++) {
            freqCount[s[right]]++;
            maxValue = max(maxValue, freqCount[s[right]]);
            while ((right - left + 1) - maxValue > k) {
                freqCount[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
