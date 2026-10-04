class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int length = 0;
        // unordered_set<char> st;
        // int left = 0;
        // for(int right = 0; right<s.length(); right++){
        //     char curr = s[right];
        //     while(st.count(curr)){
        //         st.erase(s[left]);
        //         left++;
        //     }
        //     st.insert(curr);
        //     length = max(length, right-left+1);
        // }
        // return length;
        int length = 0;
        // unordered_map<int, int> lastseen;
        vector<int> lastseen(256, -1);
        int left = 0;
        for(int right = 0; right<s.length(); right++){
            char curr = s[right];
            if(lastseen[curr] >= left){
                left = lastseen[curr]+1;
            }
            lastseen[curr] = right;
            length = max(length, right-left+1);
        }
        return length;
    }
};
