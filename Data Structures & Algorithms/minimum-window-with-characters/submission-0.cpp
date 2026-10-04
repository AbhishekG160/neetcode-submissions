class Solution {
public:
    string minWindow(string s, string t) {
        int ssize = s.length();
        int tsize = t.length();
        if(s.empty() || t.empty() || ssize<tsize)
            return "";
        
        vector<int>count(128, 0);
        for(char c:t)
            count[c]++;

        int reqd = tsize;
        int left = 0;
        int minlen = INT_MAX;
        int start = -1;

        for(int right = 0; right<ssize; right++){
            // add the char to list and decr count and reqd
            if(count[s[right]] > 0)
                reqd -= 1;
            count[s[right]]--;

            // if got all the reqd letters then shrink from the left
            while(reqd == 0){
                // save the current solution to the start and the min len
                int curlen = right-left+1;
                if(curlen < minlen){
                    minlen = curlen;
                    start = left;
                }

                // remove the left char from the list
                count[s[left]]++;
                if(count[s[left]] > 0)
                    reqd++;
                left++;
            }
        }

        return (start == -1)?"":s.substr(start, minlen);
    }
};
