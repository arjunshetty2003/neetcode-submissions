class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sCount(26, 0);
        vector<int> tCount(26, 0);

        for (char c : s) {
            sCount[ c - 'a']++;
        }

        for (char c : t) {
            tCount[c - 'a']++;
        }

        return sCount == tCount;
    }
};
