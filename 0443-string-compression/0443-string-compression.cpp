class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int read = 0; int write = 0;

        while (read < n) {
            int count = 0;
            char CurrentChar = chars[read]; 

            while (read < n && chars[read] == CurrentChar) {
                read++; count++;
            }

            chars[write++] = CurrentChar;

            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
            
        }

        return write;
    }
};