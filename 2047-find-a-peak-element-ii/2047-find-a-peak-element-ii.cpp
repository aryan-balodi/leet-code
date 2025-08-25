class Solution {
public:
    int findMaxinCol(vector<vector<int>> &mat, int m, int n, int col) {
        int maxVal = -1; int rowIndex = -1;
        for (int i = 0; i < m; i++) {
            if (mat[i][col] > maxVal) {
                maxVal = mat[i][col];
                rowIndex = i;
            }
        }
        return rowIndex;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(); int n = mat[0].size();
        int low = 0; int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int index = findMaxinCol(mat,m,n,mid);

            int left = mid - 1 >= 0 ? mat[index][mid - 1] : -1;
            int right = mid + 1 < n ? mat[index][mid + 1] : -1;

            if (mat[index][mid] > left && mat[index][mid] > right) return {index,mid}; 
            else if (mat[index][mid] < left) high = mid - 1;
            else low = mid + 1;
        }
        return {-1,-1};
    }
};