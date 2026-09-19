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
        // each account name is its own parent 
        for(int i=0; i<n; i++)
            parent[i] = i;

        unordered_map<string , int> mailtoAcc;
        // map emails to their account name
        // if unique mail then assign the current account number 
        // else find the older account number having the same mail

        for(int acc=0; acc<n; acc++) // traverse accounts
            for(int mail=1; mail<accounts[acc].size(); mail++){
                string email = accounts[acc][mail];
                
                if(mailtoAcc.find(email) != mailtoAcc.end()){
                    //already seen email -> union operation bw accounts
                    int root1 = find(acc, parent);
                    int root2 = find(mailtoAcc[email], parent);
                    if(root1 != root2)
                        parent[root1] = root2;
                } else {
                    mailtoAcc[email] = acc;
                }
            }
        
        // all emails attached to their proper accounts or children of them
        // group emails with root parent of their account id
        unordered_map<int, vector<string>> root_emails;
        for(auto& pair:mailtoAcc){
            string mail = pair.first;
            int accid = pair.second;
            int root = find(accid, parent);
            root_emails[root].push_back(mail);
        }

        // name of account - emails --> need this format
        vector<vector<string>> mergedAccounts;
        for(auto& pair:root_emails){
            int root = pair.first;
            vector<string>& mails = pair.second;
            sort(mails.begin(), mails.end());

            string accHolder = accounts[root][0];

            vector<string> mergedAcc;
            mergedAcc.push_back(accHolder);
            mergedAcc.insert(mergedAcc.end(), mails.begin(), mails.end());
            mergedAccounts.push_back(mergedAcc);
        }
        return mergedAccounts;
    }
};