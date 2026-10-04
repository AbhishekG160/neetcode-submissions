class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfreq = 0;
        int maxlen = 0;
        vector<int> count(26, 0);
        int left = 0;
        for(int right=0; right<s.length(); right++){
            char curr = s[right];
            count[curr-'A']++;
            maxfreq = max(maxfreq, count[curr-'A']);

            // curr window needs more than k replacements to make it have a single character
            while((right-left+1) - maxfreq >k){
                count[s[left]-'A']--;
                left++;
            }

            maxlen = max(maxlen, (right-left+1));
        }
        return maxlen;
    }
};
