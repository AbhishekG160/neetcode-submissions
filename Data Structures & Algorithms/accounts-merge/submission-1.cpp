class Solution {
public:
    int find(int i, vector<int>& parent){
        if (parent[i] == i) 
            return i;
        return parent[i] = find(parent[i], parent);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        for(int i=0; i<n; i++)
            parent[i] = i;

        unordered_map<string, int> mailtoacc;
        for(int acc=0; acc<n; acc++){
            for(int mail = 1; mail<accounts[acc].size(); mail++){
                string email = accounts[acc][mail];
                if(mailtoacc.find(email) != mailtoacc.end()){
                    int root1 = find(acc, parent);
                    int root2 = find(mailtoacc[email] , parent);
                    if(root1 != root2)
                        parent[root1] = root2;
                }
                else {
                    mailtoacc[email] = acc;
                }
            }
        }

        unordered_map<int, vector<string>> acctomails;
        for(auto& pair:mailtoacc){
            string email = pair.first;
            int account = pair.second;
            account = find(account , parent);
            acctomails[account].push_back(email);
        }

        vector<vector<string>> result;
        for(auto& pair:acctomails){
            int acc = pair.first;
            vector<string>& mails = pair.second;
            sort(mails.begin(), mails.end());
            vector<string> merged;
            merged.push_back(accounts[acc][0]);
            merged.insert(merged.end(), mails.begin(), mails.end());
            result.push_back(merged);
        }
        return result;
    }
};