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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty())   
            return 0;
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){
            return a.start < b.start;
        });
        int n = intervals.size();

        // end time of any of the concurrent meeting if less than the current meeting -> arrange the current meeting in that room
        priority_queue<int, vector<int>, greater<int>> minh; // track the min ending time 
        minh.push(intervals[0].end);
        for(int i=1; i<n; i++){
            int prev_end = minh.top();
            int new_end;
            if(intervals[i].start >= prev_end)
                minh.pop();
            minh.push(intervals[i].end);
        }
        return minh.size();
    }
};
