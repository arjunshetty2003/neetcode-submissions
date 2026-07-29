class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
           return 0;

        unordered_set<char> seen;
        int left = 0;
        int right = 0;

        int n = s.length();

        int maxSize = 1;

        while (right < n) {
            if (!seen.count(s[right])) {
                seen.insert(s[right]);
                right++;
                maxSize = max(maxSize, right - left);
            }
            else {
                seen.erase(s[left]);
                left++;
            }
        }

        return maxSize;
    }
};
