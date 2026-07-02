class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> sCount(26, 0);
        vector<int> tCount(26, 0);

        for (char c : s) {
            sCount[c - 'a']++;
        }

        for (char c : t) {
            tCount[c - 'a']++;
        }

        if (sCount == tCount) {
            return true;
        }
        else {
            return false;
        }
    }
};
