class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
             
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        for(auto& edge:edges){
            deg[edge[0]]++;
            deg[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // remove from the leaves to get the centers of tree
        queue<int> q;
        for(int i=0; i<n; i++)
            if(deg[i] == 1)
                q.push(i);
        
        int remaining = n;
        while(remaining > 2){
            int leaf = q.size();
            remaining -= leaf;

            for(int i=0; i<leaf; i++){
                int curr = q.front();
                q.pop();
                for(int next : adj[curr]){
                    deg[next]--;
                    if(deg[next] == 1)
                        q.push(next);
                }
            }
        }

        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};