class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.size();
        if (len == 0) return true;
        if (len == 1) return s1[0] == s2[0];
        int i;
        if (s1 == s2) return true;
        if (!sameCharacter(s1,s2)) return false;
        string s11, s12, s21, s22, s23, s24;
        for (i = 1; i <= len - 1; i++) {
            s11 = s1.substr(0,i);
            s12 = s1.substr(i,len-i);
            s21 = s2.substr(0,i);
            s22 = s2.substr(i,len-i);
            s23 = s2.substr(0,len-i);
            s24 = s2.substr(len-i,i);
            if ((isScramble(s11,s21) && isScramble(s12,s22)) || (isScramble(s11,s24) && isScramble(s12,s23))) return true;
        }
        return false;
    }
    bool sameCharacter(string a, string b) {
        int characters[26] = {0};
        int len = a.size(), i, pos;
        for (i = 0; i < len; i++) {
            characters[a[i]-'a']++;
            characters[b[i]-'a']--;
        }
        for (i = 0; i < 26; i++) {
            if (characters[i] != 0) return false;
        }
        return true;
    }
};