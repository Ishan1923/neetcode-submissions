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
    struct comp{
        bool operator()(const Interval& a, const Interval& b){
            return a.end > b.end;
        }
    };
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });
        priority_queue<Interval, vector<Interval>, comp> q;
        int rooms = 0;

        for(int i = 0; i < intervals.size(); i++){

            while(!q.empty() && intervals[i].start >= q.top().end){
                q.pop();
            }
            q.push(intervals[i]);
            rooms = max(rooms, static_cast<int>(q.size()));
        }
        return rooms;
    }
};
