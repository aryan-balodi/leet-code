class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> answer(n,vector<int>(n));
        int top = 0; int left = 0; int bottom = n - 1; int right = n - 1;
        int num = 1; int maxNum = n * n;

        while (num <= maxNum) {
            for (int i = left; i <= right && num <= maxNum; i++) {
                answer[top][i] = num++;
            }
            top++;

            for (int i = top; i <= bottom && num <= maxNum; i++) {
                answer[i][right] = num++;
            }
            right--;

            for (int i = right; i >= left && num <= maxNum; i--) {
                answer[bottom][i] = num++;
            }
            bottom--;

            for (int i = bottom; i >= top && num <= maxNum; i--) {
                answer[i][left] = num++;
            }
            left++;
        }
        return answer;
    }
};