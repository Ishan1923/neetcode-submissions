class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        vector<pair<int, string>>& vec = mp[key];
        // sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        //     return a.first > b.first;
        // });

        int low = 0, high = vec.size() - 1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(vec[mid].first <= timestamp){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        if(ans == -1){
            return "";
        }

        return vec[ans].second;
        
    }
};
