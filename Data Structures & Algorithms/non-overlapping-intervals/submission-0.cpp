class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[1] == b[1])    
                return a[0]<b[0];
            return a[1]<b[1];
        });
        int prev_end = intervals[0][1];
        for(int i=1; i<n; i++){
            if(prev_end <= intervals[i][0])
                prev_end = intervals[i][1];
            else count++;
        }
        return count;
    }
};
