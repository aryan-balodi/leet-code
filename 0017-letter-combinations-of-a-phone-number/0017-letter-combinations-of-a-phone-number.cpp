class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string current;
        vector<string> mapping = {
            "",     "",     "abc", "def", "ghi", "jkl",
            "mno",  "pqrs", "tuv", "wxyz"
        };
        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                res.push_back(current);
                return;
            }
            for (char c : mapping[digits[index] - '0']) {
                current.push_back(c);
                backtrack(index + 1);
                current.pop_back();
            }
        };
        backtrack(0);
        return res;
    }
};
