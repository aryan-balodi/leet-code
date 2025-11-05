class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; int right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int min_h = min(height[left],height[right]);
            int area = (right - left) * min_h;
            maxArea = max(area,maxArea);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};