class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<bool> valid(n, false);
        valid[0] = true;
        int reachables = 0;
        for(int j = 1; j<n; j++){
            if(j-minJump >= 0){
                if(valid[j-minJump])
                    reachables++;
            }
            if(j-(maxJump+1) >= 0){
                if(valid[j-(maxJump+1)])
                    reachables--;
            }
            if(s[j] == '0' && reachables > 0)
                valid[j] = true; 
        }
        return valid[n-1];
    }
};