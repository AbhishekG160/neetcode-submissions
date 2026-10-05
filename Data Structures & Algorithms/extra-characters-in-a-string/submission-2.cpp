class Solution {
public:
    // int helper(int idx, string s, unordered_set<string>& dict, vector<int>& dp){
    //     if(idx >= s.length())
    //         return 0;
    //     // assume current as extra
    //     if(dp[idx] != -1)
    //         return dp[idx];
    //     int extras = 1 + helper(idx+1, s, dict, dp);
    //     // assume a string curr exists
    //     string curr = "";
    //     for(int j=idx; j<s.length(); j++){
    //         curr += s[j];
    //         if(dict.count(curr))
    //             extras = min(extras, helper(j+1, s, dict, dp));
    //     }
    //     return dp[idx] = extras;
    // }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        // vector<int> dp(s.length(), -1);
        int n = s.length();
        vector<int> dp(n+1, 0);
        for(int idx=n-1; idx>=0; idx--){
            // extra assumed
            dp[idx] = 1+dp[idx+1];
            // find string from idx
            string curr = "";
            for(int j=idx; j<n; j++){
                curr += s[j];
                if(dict.count(curr))
                    dp[idx] = min(dp[idx] , dp[j+1]);
            }
        }
        // return helper(0, s, dict, dp);
        return dp[0];
    }
};