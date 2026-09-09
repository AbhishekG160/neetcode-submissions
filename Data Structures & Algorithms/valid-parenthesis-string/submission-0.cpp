class Solution {
public:
    bool checkValidString(string s) {
        // ( -> triggers increase in open parenthesis and ) -> decrease in open parenthesis
        // * -> can either be ( -> inc count or ) -> dec count or just empty -> no diff
        // maintain range as minopen and maxopen
        // max open < 0 -> ) is more than * and ( both -> return false
        // min open < 0 -> assumed * as ) when no needed -> minopen = max(0, minopen)
        int minopen = 0;
        int maxopen = 0;
        for(char& c:s){
            if(c == '('){
                maxopen++;
                minopen++;
            }
            else if(c == ')'){
                minopen--;
                maxopen--;
            }
            else{
                maxopen++;
                minopen--;
            }
            if(maxopen < 0)
                return false;
            minopen = max(minopen , 0); 
        }
        return minopen == 0;
    }
};
