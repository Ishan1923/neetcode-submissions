class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged_intervals;
        merged_intervals.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            auto& prev_interval = merged_intervals.back();
            auto& curr_interval = intervals[i];
            if(curr_interval[0] <= prev_interval[1]){
                merged_intervals.back()[1] = max(prev_interval[1], curr_interval[1]);
            }
            else{
                merged_intervals.push_back(curr_interval);
            }
        }
        return merged_intervals;
    }
};
