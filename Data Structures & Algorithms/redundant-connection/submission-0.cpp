class Solution {
public:
    int find(int node, vector<int>& parent){
        if(node == parent[node])
            return node;
        return parent[node] = find(parent[node] , parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i=0; i<=n; i++)
            parent[i] = i;
        vector<pair<int,int>> redundants;
        for(auto& edge:edges){
            int rootx = find(edge[0], parent);
            int rooty = find(edge[1], parent);
            if(rootx != rooty){
                parent[rooty] = rootx;
            }else{
                redundants.push_back({edge[0], edge[1]});
            }
        }
        int x = redundants.back().first;
        int y = redundants.back().second;
        return (redundants.empty())?vector<int>{}:vector<int>{x,y};
    }
};
