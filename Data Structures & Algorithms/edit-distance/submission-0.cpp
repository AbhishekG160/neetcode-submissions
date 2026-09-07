class Solution {
public:
    int minDistance(string s1, string s2) {
        // insert - s2 char added to s1 --> j--
        // delete - s1 char removed --> i--
        // replace - s2 char copied to s1 --> i--, j--
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++) 
            dp[i][0] = i; // deletions
        for(int j=1; j<=m; j++)
            dp[0][j] = j; // insertions

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1]; // no operations
                else dp[i][j] = 1+ min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
        return dp[n][m];
    }
};
