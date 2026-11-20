class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0;
        unordered_map<char, int> mp;
        int n = s.length();
        int maxLen = 0;
        int left = 0;
        int right = 0;
        for (right; right < n; right++) {
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);
            while ((right - left + 1) - maxFreq > k) {
                mp[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
