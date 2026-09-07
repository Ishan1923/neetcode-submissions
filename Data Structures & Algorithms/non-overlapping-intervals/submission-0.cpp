class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int prevEnd;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[1] < b[1];});
        prevEnd = intervals[0][1];
        int count = 0;
        for(int i = 1; i < intervals.size(); i++){
            auto& curr = intervals[i];

            if(prevEnd > curr[0]){
                count++;
            }
            else{
                prevEnd = curr[1];
            }
        }
        return count;
    }
};
