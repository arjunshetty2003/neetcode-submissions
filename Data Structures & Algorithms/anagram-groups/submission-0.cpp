class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagramIndex;

        for (string s : strs) {
            vector<int> freq(26, 0);
            
            for (char c : s) {
                freq[c - 'a']++;
            }

            string key;
            for (int i : freq) {
                key += to_string(i) + "#";
            }

            anagramIndex[key].push_back(s);
        }

        for (auto &entry : anagramIndex) {
            result.push_back(entry.second);
        }

        return result;
    }
};
