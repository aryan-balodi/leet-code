class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int end = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (num[i] % 2 != 0) {
                end = i;
                break;
            }
        }
        if (end == -1) return "";
        else return num.substr(0, end + 1);

    }
};