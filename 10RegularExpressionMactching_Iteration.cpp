class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size(), plen = p.size(), i, j;
        vector<vector<bool> > opt(slen+1, vector<bool>(plen+1, false));
        opt[0][0] = true;
        i = 0;
        for (j = 1; j <= plen-1; j++) {
            if (p[j-1] == '*') opt[i][j] = true;
            else {
                if (p[j] == '*') {
                    opt[i][j+1] = true;
                    j++;
                } else {
                    break;
                }
            }
        }
        if (plen > 0) {
            for (i = 1; i <= slen; i++) {
                j = 1;
                if (s[i-1] == p[j-1] || p[j-1] == '.') opt[i][j] = opt[i-1][j-1];
                else opt[i][j] = false;
                for (j = 2; j <= plen; j++) {
                    if (p[j-1] == '*') {
                        if (p[j-2] != s[i-1] && p[j-2] != '.') opt[i][j] = opt[i][j-2];
                        else opt[i][j] = opt[i-1][j] + opt[i][j-2] + opt[i-1][j-2];
                    } else if (s[i-1] == p[j-1] || p[j-1] == '.') opt[i][j] = opt[i-1][j-1];
                    else opt[i][j] = false;
                }
            }
        }
        return opt[slen][plen];
    }
};