class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result;
        for (string s : tokens) {
            if (s == "+") {
                int num2;
                int num1;
                if (!st.empty()) {
                    num2 = st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    num1 = st.top();
                    st.pop();
                }
                int res = num1 + num2;
                st.push(res);
            }
            else if (s == "-") {
                int num2;
                int num1;
                if (!st.empty()) {
                    num2 = st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    num1 = st.top();
                    st.pop();
                }
                int res = num1 - num2;
                st.push(res);
            }
            else if (s == "*") {
                int num2;
                int num1;
                if (!st.empty()) {
                    num2 = st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    num1 = st.top();
                    st.pop();
                }
                int res = num1 * num2;
                st.push(res);
            }
            else if (s == "/") {
                int num2;
                int num1;
                int res;
                if (!st.empty()) {
                    num2 = st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    num1 = st.top();
                    st.pop();
                }
                if (num2 == 0) {
                    res = 0;
                }
                else {
                    res = num1 / num2;
                }
                st.push(res);
            }
            else {
                int res = stoi(s);
                st.push(res);
            }
        }
        if (!st.empty()) {
            result = st.top();
            st.pop();
        }
        return result;
    }
};
