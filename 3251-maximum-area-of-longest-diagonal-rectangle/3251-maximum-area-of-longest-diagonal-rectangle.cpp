class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal = 0; int maxArea = 0;
        int m = dimensions.size(); int n = dimensions[0].size();
        for (int i = 0; i < m; i++) {
            int len = dimensions[i][0]; int wid = dimensions[i][1];
            int diagonal_len = len * len + wid * wid;
            int area = len * wid;

            if (diagonal_len > maxDiagonal) {
                maxDiagonal = diagonal_len;
                maxArea = area;
            }
            else if (diagonal_len == maxDiagonal) {
                maxArea = max(area,maxArea);
            }
        }
        return maxArea;
    }
};