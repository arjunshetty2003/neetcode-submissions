class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> lessThanIndex;
        for (int i = 0; i < n; i++) {
            if (lessThanIndex.empty() || temperatures[lessThanIndex.top()] >= temperatures[i]) {
                lessThanIndex.push(i);
            }
            else {
                while(!lessThanIndex.empty() && temperatures[lessThanIndex.top()] < temperatures[i]) {
                    result[lessThanIndex.top()] = i - lessThanIndex.top();
                    lessThanIndex.pop();
                }
                lessThanIndex.push(i);
            }
        }
        return result;
    }
};
