class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> keyMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (keyMap.count(key) == false)
            return "";

        int left = 0;
        int right = keyMap[key].size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (keyMap[key][mid].first == timestamp)
                return keyMap[key][mid].second;
            else if (keyMap[key][mid].first < timestamp)
                left = mid + 1;
            else 
                right = mid - 1;
        }

        if (right >= 0)
            return keyMap[key][right].second;

        return "";
    }
};
