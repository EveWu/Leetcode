class Solution {
public:
    bool isMatch(string s, string p) {
        return recursive(s, p, s.size(), p.size());
    }
    bool recursive(string s, string p, int slen, int plen) {
        int i = slen - 1, j = plen - 1;
        if (slen == 0) {
            if (plen == 0) {
                return true;
            } else if (plen == 1) {
                if (p[j] == '*') return true;
                else return false;
            } else {
                if (p[j] == '*') {
                    if (p[j-1] == '*') return recursive(s, p, slen, plen-1);
                    else return recursive(s, p, slen, plen-2); 
                }
                else {
                    return false;
                }
            }
        } else {
            if (plen == 0) return false;
            else if (plen == 1) {
                if (s[i] == p[j] || p[j] == '.') {
                    return recursive(s, p, slen-1, plen-1);
                } else {
                    return false;
                }
            } else {
                if (s[i] == p[j] || p[j] == '.') {
                    return recursive(s, p, slen-1, plen-1);
                } else if (p[j] == '*') {
                    // set to 0
                    if (p[j-1] != s[i] && p[j-1] != '.') {
                        return recursive(s, p, slen, plen-2);
                    } else {
                        return recursive(s, p, slen-1, plen) || recursive(s, p, slen-1, plen-2) || recursive(s, p, slen, plen-2);
                    }
                } else {
                    return false;
                }
            }
        }
    }
};