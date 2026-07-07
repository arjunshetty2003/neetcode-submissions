class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }

        int n = s.length();
        int left = 0, right = 0;
        int maxLen = 1;
        unordered_set<char> seen;

        while (right < n) {
            if (!seen.count(s[right])) {
                seen.insert(s[right]);
                right++;
                maxLen = max(maxLen, right - left);
            }
            else {
                seen.erase(s[left]);
                left++;
            }
        }   
        
        return maxLen;
    }
};
