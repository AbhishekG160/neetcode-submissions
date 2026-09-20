class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto& time:times){
            int u = time[0];
            int v = time[1];
            int t = time[2];
            adj[u].push_back({v, t});
        }
        // distance - curr node
        priority_queue<pair<int , int>, vector<pair<int , int>>, greater<pair<int , int>>> pq;
        pq.push({0, k});
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        while(!pq.empty()){
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(cost > dist[node])
                continue;
            for(auto& jump:adj[node]){
                int next = jump.first;
                int d = jump.second;
                if(d + cost < dist[next]){
                    dist[next] = d+cost;
                    pq.push({dist[next] , next});
                }
            }
        }

        int result = INT_MIN;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX)
                return -1;  
            else if(dist[i] > result)
                result = dist[i];
        }
        return result;
    }
};
