class Solution {
public:
    int find(int node, vector<int>& parent){
        if(node == parent[node])
            return node;
        return parent[node] = find(parent[node] , parent);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // nodes n --> edges n-1
        // no cycle
        // fully connected
        if(edges.size() != n-1)
            return false;
        vector<int> parent(n);
        for(int i=0; i<n; i++) parent[i] = i;
    
        for(auto& edge:edges){
            int parenta = find(edge[0] , parent);
            int parentb = find(edge[1] , parent);
            if(parenta == parentb)
                return false;
            parent[parenta] = parentb;
        }
        return true;
    }
};
