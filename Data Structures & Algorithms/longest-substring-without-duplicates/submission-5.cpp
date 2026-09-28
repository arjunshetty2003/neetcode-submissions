class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;

        int left = 0;
        int right = 0;

        unordered_set<char> hasSeen;

        int n = s.length();

        while (right < n) {
            if (!hasSeen.count(s[right])) {
                hasSeen.insert(s[right]);
                right++;

                maxLen = max(maxLen, right - left);
            }
            else {
                hasSeen.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }
};
