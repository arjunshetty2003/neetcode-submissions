class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;

        for (string str : strs) {
            int n = str.length();
            encoded_string += to_string(n) + "#" + str;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int n = s.length();
        int i = 0;

        while (i < n) {
            string numString;
            while (s[i] != '#') {
                numString += s[i];
                i++;
            }
            int len = stoi(numString);
            i++;

            result.push_back(s.substr(i, len));
            
            i += len;

        }

        return result;
    }
};
