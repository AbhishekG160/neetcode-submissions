class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000")
            return 0;

        unordered_set<string> dead;
        for(string d:deadends) {
            dead.insert(d);
            if(d == "0000")
                return -1;
        }

        queue<string> q;
        q.push("0000");
        dead.insert("0000");

        int turns = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){

                string curr = q.front();
                q.pop();
                if(curr == target)
                    return turns;

                for(int i=0; i<4; i++){
                    char org = curr[i];

                    curr[i] = (org == '9')?'0':org+1;
                    if(!dead.count(curr)){
                        dead.insert(curr);
                        q.push(curr);
                    }
                    curr[i] = (org == '0')?'9':org-1;
                    if(!dead.count(curr)){
                        dead.insert(curr);
                        q.push(curr);
                    }

                    curr[i] = org;
                }
            }
            turns++;
        }
        return -1;
    }
};