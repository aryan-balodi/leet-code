class Solution {
public:
    string removeOccurrences(string s, string part) {
        int length = part.size(); 
        while (s.find(part) < s.size()) {
            int start = s.find(part); 
            s.erase(start,length);
        }
        return s;    
    }
};