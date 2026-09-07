/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.end < b.end;
        });
        int prevEnd = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++){
            auto& curr = intervals[i];
            if(prevEnd > curr.start) return false;
            else prevEnd = curr.end;
        }
        return true;
    }
};
