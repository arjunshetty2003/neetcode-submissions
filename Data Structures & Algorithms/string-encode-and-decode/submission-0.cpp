class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        for (string word : strs) {
            int len = word.length();
            result += to_string(len) + "#" + word;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int n = s.length();
        int i = 0;
        while (i < n) {
            string lenStr;
            while (s[i] != '#') {
                lenStr += s[i];
                i++;
            }
            int len = stoi(lenStr);
            i++;
            string word;
            while (len > 0) {
                word += s[i];
                len--;
                i++;
            }
            result.push_back(word); 
        }
        return result;
    }
};
