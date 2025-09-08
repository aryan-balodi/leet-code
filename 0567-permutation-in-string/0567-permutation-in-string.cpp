class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> s1Freq(26,0); vector<int> FreqInWindow(26,0);

        for (char c : s1) s1Freq[c - 'a']++;

        for (int i = 0; i < s2.size(); i++) {
            FreqInWindow[s2[i] - 'a']++;

            if (i >= s1.size()) {
                FreqInWindow[s2[i - s1.size()] - 'a']--;
            }
            if (s1Freq == FreqInWindow) return true;
        }
        return false;
    }
};