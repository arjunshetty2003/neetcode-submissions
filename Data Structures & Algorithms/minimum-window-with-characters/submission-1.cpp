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

        int left = 0;
        int right = 0;
        int minStart = 0;

        int minLength = INT_MAX;

        int n = s.length();

        vector<int> sMap(256, 0);
        vector<int> tMap(256, 0);

        for (char c : t) {
            tMap[c]++;
        }

        while (right < n) {
            sMap[s[right]]++;

            while(compare(sMap, tMap)) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minStart = left;
                }
                sMap[s[left]]--;
                left++;
            }

            right++;
        }
        return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
    }
};
