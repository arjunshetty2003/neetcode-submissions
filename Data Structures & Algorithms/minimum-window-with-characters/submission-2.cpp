class Solution {
private:
    bool compare(vector<int> s, vector<int> t) {
        for (int i = 0; i < 256; i++) {
            if (s[i] < t[i])
               return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
           return "";

        if (s.length() < t.length())
           return "";

        int n = s.length();
        int left = 0;
        int right = 0;
        int minStart = 0;
        int minLen = INT_MAX;

        vector<int> sMap(256, 0);
        vector<int> tMap(256, 0);

        for (char c : t) {
            tMap[c]++;
        }

        while (right < n) {
            sMap[s[right]]++;

            while(compare(sMap, tMap)) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                sMap[s[left]]--;
                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
