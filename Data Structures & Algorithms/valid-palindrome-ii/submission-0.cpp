class Solution {
    bool recurse(int i, int j, string& s){
        while(i<j){
            if(s[i] != s[j])
                return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int i=0, j=n-1;
        while(i<j){
            if(s[i] != s[j]){
                return recurse(i, j-1, s) || recurse(i+1, j, s);
            }
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};