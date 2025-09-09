class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> freq_s(26,0); vector<int> freq_t(26,0);

        for (int index_s = 0; index_s < s.size(); index_s++) {
            freq_s[s[index_s] - 'a']++;
        }

        for (int index_t = 0; index_t < t.size(); index_t++) {
            freq_t[t[index_t] - 'a']++;
        }

        return freq_s == freq_t;
    }
};