class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // k airports without the src and dest --> src (k points) dest --> k+1 jumps
        // k+1 used in bellmann ford --> from src to points reachable in K+1 jumps
        vector<int> dist(n, 1e8);
        dist[src] = 0;
        for(int i=0; i<=k; i++){
            // copy the dist to use the current values and not the updated dist in the loop
            vector<int> temp = dist; // act as updated

            for(auto& flight:flights){
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];
                if(price + dist[u] < temp[v])
                    temp[v] = price+dist[u];
            }

            dist = temp;
        }

        return (dist[dst] == 1e8)?-1:dist[dst];
    }
};
