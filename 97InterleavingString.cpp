class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size(), i, j, k;
        if (len3 != len1 + len2) return false;
        if (len3 == 0) return true;
        int characters[26] = {0};
        for (i = 0; i < len1; i++) characters[s1[i]-'a']++;
        for (i = 0; i < len2; i++) characters[s2[i]-'a']++;
        for (i = 0; i < len3; i++) characters[s3[i]-'a']--;
        for (i = 0; i < 26; i++) if (characters[i] != 0) return false;
        // k = i + j
        vector<vector<bool> > dp(len1+1, vector<bool>(len2+1,false));
        dp[0][0] = true;
        i = 0;
        for (j = 1; j <= len2; j++) {
            if (s2[j-1] != s3[j-1]) break;
            else dp[i][j] = true;
        }
        j = 0;
        for (i = 1; i <= len1; i++) {
            if (s1[i-1] != s3[i-1]) break;
            else dp[i][j] = true;
        }
        for (i = 1; i <= len1; i++) {
            for (j = 1; j <= len2; j++) {
                k = i + j;
                if (s1[i-1] == s3[k-1] && s2[j-1] == s3[k-1]) dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else if (s1[i-1] == s3[k-1]) dp[i][j] = dp[i-1][j];
                else if (s2[j-1] == s3[k-1]) dp[i][j] = dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[len1][len2];
    }
};