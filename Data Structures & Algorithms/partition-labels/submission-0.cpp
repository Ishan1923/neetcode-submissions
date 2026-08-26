class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, pair<int, int>> intervals;
        for(int i = 0; i < n; i++){
            
            if(intervals.find(s[i]) == intervals.end()){
                intervals[s[i]] = {i, i};
            }
            else{
                intervals[s[i]].first = min(intervals[s[i]].first, i);
                intervals[s[i]].second = max(intervals[s[i]].second, i);
            }

        }


        vector<vector<int>> intrs;


        for(auto& [c, interval] : intervals){
            intrs.push_back({interval.first, interval.second});
        }


        sort(intrs.begin(), intrs.end());


        vector<pair<int, int>> merged;
        for(int i = 0; i < intrs.size(); i++){

            auto interval = intrs[i];

            if(!merged.empty() && interval[0] <= merged.back().second){
                merged.back().second = max(merged.back().second, interval[1]);
            }
            else{
                merged.push_back({interval[0], interval[1]});
            }


        }



        vector<int> result;

        for(int i = 0 ; i < merged.size(); i++){
            result.push_back(merged[i].second - merged[i].first + 1);
        }


        return result;



    }
};
