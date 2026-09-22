class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist(n, INT_MAX); // minm dist to reach the point i from any of the other points 
        vector<bool> in_mst(n, false); 

        dist[0] = 0;
        int total = 0;

        for(int steps = 0; steps<n; steps++){
            int u = -1;

            // find unvisited node which is closest to any of visited node
            for(int i=0; i<n; i++){
                if(!in_mst[i] && (u==-1 || dist[i] <= dist[u]))
                    u = i;
            }

            // make it visited
            in_mst[u] = true;
            total += dist[u];

            // check if some node is closer to it that any other visited nodes
            for(int i=0; i<n; i++)
                if(!in_mst[i]){
                    int d = abs(points[u][0]-points[i][0]) + abs(points[u][1]-points[i][1]);
                    if(d < dist[i])
                        dist[i] = d;
                }   
        }

        return total;
    }
};
