class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int, int>> maxh;
        for(int i=0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            maxh.push({dist, i});
            if(maxh.size() > k)
                maxh.pop();
        }
        
        while(!maxh.empty()){
            auto pair = maxh.top();
            maxh.pop();
            int idx = pair.second;
            result.push_back({points[idx][0] , points[idx][1]});
        }
        return result;
    }
};
