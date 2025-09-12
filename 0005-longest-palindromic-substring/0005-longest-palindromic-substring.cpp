class Solution {
public:
    string longestPalindrome(string s) {
       if (s.length() <= 1) return s;

       string answer = "";

       for (int i = 0; i < s.length(); i++) {
        int low = i; int high = i;

        while (low >= 0 && high < s.length() && s[low] == s[high]) {
            low--;
            high++;
        }

        string pallindrome = s.substr(low + 1, high - low - 1);
        if (pallindrome.length() > answer.length()) answer = pallindrome;

        low = i; high = i + 1;

        while (low >= 0 && high < s.length() && s[low] == s[high]) {
            low--;
            high++;
        }

        pallindrome = s.substr(low + 1, high - low - 1);
        if (pallindrome.length() > answer.length()) answer = pallindrome;
        
       } 

       return answer;
    }
};