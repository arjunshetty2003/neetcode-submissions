class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
    if (n > m) return false;

    vector<int> diff(26, 0);
    for (char c : s1) diff[c - 'a']--;

    int i = 0;
    for (; i < n; i++) diff[s2[i] - 'a']++;

    int zeros = 0;
    for (int d : diff) if (d == 0) zeros++;
    if (zeros == 26) return true;

    for (; i < m; i++) {
        int add = s2[i] - 'a';
        int rem = s2[i - n] - 'a';

        // update add
        if (diff[add] == 0) zeros--;
        diff[add]++;
        if (diff[add] == 0) zeros++;

        // update rem
        if (diff[rem] == 0) zeros--;
        diff[rem]--;
        if (diff[rem] == 0) zeros++;

        if (zeros == 26) return true;
    }
    return false;
    }
};
