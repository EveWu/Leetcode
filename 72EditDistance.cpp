class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size(), i, j;
        vector<vector<int> > dp(len1+1,vector<int>(len2+1, 0));
        i = 0;
        for (j = 1; j <= len2; j++) {
            dp[i][j] = j;
        }
        j = 0;
        for (i = 1; i <= len1; i++) {
            dp[i][j] = i;
        }
        for (i = 1; i <= len1; i++) {
            for (j = 1; j <= len2; j++) {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
            }
        }
        return dp[len1][len2];
    }
};