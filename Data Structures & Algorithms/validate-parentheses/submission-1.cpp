class Solution {
public:
    bool isValid(string s) {
        stack<char> exists;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                exists.push(s[i]);
            }
            else {
                if (s[i] == ')') {
                    if (!exists.empty()) {
                        if (exists.top() == '(') {
                            exists.pop();
                            continue;
                        }
                        else {
                            return false;
                        }
                    }
                    else {
                        return false;
                    }
                }
                else if (s[i] == ']') {
                    if (!exists.empty()) {
                        if (exists.top() == '[') {
                            exists.pop();
                            continue;
                        }
                        else {
                            return false;
                        }
                    }
                    else {
                        return false;
                    }
                }
                else if (s[i] == '}') {
                    if (!exists.empty()) {
                        if (exists.top() == '{') {
                            exists.pop();
                            continue;
                        }
                        else {
                            return false;
                        }
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        if (exists.empty())
           return true;
        else
           return false;
    }
};
