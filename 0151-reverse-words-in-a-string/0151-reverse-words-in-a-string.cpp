class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        // Use a stringstream to extract words, automatically ignoring extra spaces
        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        // Join words with a single space
        string result;
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) result += " ";
            result += words[i];
        }
        return result;
    }
};
