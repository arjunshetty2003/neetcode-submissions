class Solution {
public:
    string minWindow(string s, string t) {
    if (t.empty() || s.empty()) return "";

    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int required = need.size();
    int formed = 0;

    int left = 0, minLen = INT_MAX, minStart = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;

        if (need.count(c) && window[c] == need[c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }
            char lc = s[left];
            window[lc]--;
            if (need.count(lc) && window[lc] < need[lc]) {
                formed--;
            }
            left++;
        }
    } // <-- for loop closes HERE

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen); // <-- now outside the loop
}
};
