class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int length = 0;
        // // unordered_map<int, int> lastseen;
        // vector<int> lastseen(256, -1);
        // int left = 0;
        // for(int right = 0; right<s.length(); right++){
        //     char curr = s[right];
        //     if(lastseen[curr] >= left){
        //         left = lastseen[curr]+1;
        //     }
        //     lastseen[curr] = right;
        //     length = max(length, right-left+1);
        // }
        // return length;

        int left = 0;
        vector<int> lastseen(128, -1);
        int n = s.length();
        int len = 0;
        for(int right=0; right<n; right++){
            char curr = s[right];
            if(lastseen[curr] >= left)
                left = lastseen[curr]+1;
            lastseen[curr] = right;
            len = max(len, right-left+1);
        }
        return len;
    }
};
