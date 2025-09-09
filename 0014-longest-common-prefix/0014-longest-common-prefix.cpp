class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string reference = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < reference.size() && j < strs[i].size() && reference[j] == strs[i][j]) j++;
            
            reference = reference.substr(0,j);
            if (reference.empty()) return "";
        }

        return reference;

        
    }
};
