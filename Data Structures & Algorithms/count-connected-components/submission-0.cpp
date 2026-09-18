class Solution {
public:
    int find(int node, vector<int>& parent){
        if(node == parent[node])
            return node;
        return parent[node] = find(parent[node], parent);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        int component = n;
        for(int i=0; i<n; i++)
            parent[i] = i;
        
        for(auto& edge:edges){
            int rootx = find(edge[0] , parent);
            int rooty = find(edge[1] , parent);
            if(rootx != rooty){
                parent[rooty] = rootx;
                component--;
            }
        }
        return component;
    }
};
