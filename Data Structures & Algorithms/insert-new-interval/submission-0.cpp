class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if(intervals.empty()) return {newInterval};

        vector<vector<int>> merged_intervals;


        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());


        merged_intervals.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            auto& prev_interval = merged_intervals.back();
            auto& curr_interval = intervals[i];

            if(prev_interval[1] >= curr_interval[0]){
                merged_intervals.back()[1] = max(curr_interval[1], prev_interval[1]);
            }
            else{
                merged_intervals.push_back(curr_interval);
            }

        }

        return merged_intervals;

    }
};
