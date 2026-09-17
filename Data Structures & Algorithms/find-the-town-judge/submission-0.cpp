class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int, int>> trusts_trustedby(n);
        for(int i=0; i<n; i++) trusts_trustedby[i] = {0,0};
        for(auto& t:trust){
            int u = t[0]-1;
            int v = t[1]-1;
            trusts_trustedby[u].first += 1;
            trusts_trustedby[v].second += 1;
        }
        int result = -1;
        for(int i=0; i<n; i++)
            if(trusts_trustedby[i].first == 0 && trusts_trustedby[i].second == n-1) 
                result = i+1;
        return result;
    }
};