class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> str;
        int currn = 0;
        string currs = "";
        for(char c:s){
            if(isdigit(c)){
                currn = (currn*10) + (c-'0');
            }
            else if(c == '['){
                nums.push(currn);
                str.push(currs);
                currn = 0;
                currs = "";
            }
            else if(c == ']'){
                int times = nums.top();
                nums.pop();
                string prev = str.top();
                str.pop();
                string repeated = "";
                for(int i=0; i<times; i++){
                    repeated += currs;
                }
                currs = prev + repeated;
            }
            else {
                currs += c;
            }
        }
        return currs;
    }
};