class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> mapIndex;

        for (string s : strs) {
            vector<int> countIndex(26, 0);
            string index;
            for (char c : s) {
                countIndex[c - 'a']++;
            }

            for (int i : countIndex) {
                   index += (to_string(i) + "#");
            }

            mapIndex[index].push_back(s);
        }

        for (auto & entry : mapIndex) {
            result.push_back(entry.second);
        }

        return result;
    }
};
