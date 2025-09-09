class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char,char> MAP_ST;
        unordered_map<char,char> MAP_TS;

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i]; char c2 = t[i];

            if (MAP_ST.find(c1) != MAP_ST.end()) {
                if (MAP_ST[c1] != c2) return false;
            }
            else {
                MAP_ST[c1] = c2;
            }

            if (MAP_TS.find(c2) != MAP_TS.end()) {
                if (MAP_TS[c2] != c1) return false;
            }
            else {
                MAP_TS[c2] = c1;
            }
        }
        return true;
    }
};