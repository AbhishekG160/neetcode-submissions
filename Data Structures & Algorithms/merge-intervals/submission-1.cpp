class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin() , intervals.end());
        result.push_back(intervals[0]);
        for(vector<int> inter:intervals){
            if(result.back()[1] < inter[0])
                result.push_back(inter);
            else if(result.back()[1] > inter[1])
                continue;
            else 
                result.back()[1] = inter[1];            
        }
        return result;
    }
};
