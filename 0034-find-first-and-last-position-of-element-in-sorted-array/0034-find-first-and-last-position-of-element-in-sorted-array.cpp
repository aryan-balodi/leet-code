class Solution {
public:

    int LB (vector<int> &nums, int target) {
        int n = nums.size();
        int ans = n;
        int low = 0; int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int UB (vector<int> &nums, int target) {
        int n = nums.size();
        int ans = n;
        int low = 0; int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
                ans = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = LB(nums,target);
        if (lb == nums.size() || nums[lb] != target) return {-1,-1};
        return {lb, UB(nums,target) - 1};
    }
};