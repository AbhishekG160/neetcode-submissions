class Solution {
public:
    double dfs(string u, string target, unordered_map< string , vector<pair<string, double>> >& adj , unordered_set<string>& visit, double product){
        if(u == target)  
            return product;
        visit.insert(u);

        for(auto& neigh:adj[u]){
            string next = neigh.first;
            double weight = neigh.second;
            if(visit.find(next) == visit.end()){ // not visited
                // move to next node
                double val = dfs(next, target, adj, visit, product*weight);
                if(val != -1.0) // found target
                    return val;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map< string , vector<pair<string, double>> > adj;
        for(int i=0; i<n; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0/val});
        }

        vector<double> results;
        for(auto& query:queries){
            string start = query[0];
            string target = query[1];
            if(adj.find(start) == adj.end() || adj.find(target) == adj.end()){
                results.push_back(-1.0);
                continue;
            }
            if(start == target){
                results.push_back(1.0);
                continue;
            }
            unordered_set<string> visit;
            results.push_back( dfs(start, target, adj, visit, 1.0) );
        }

        return results;
    }
};