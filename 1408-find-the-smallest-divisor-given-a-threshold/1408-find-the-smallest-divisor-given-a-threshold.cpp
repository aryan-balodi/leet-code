class Solution {
public:
    int sumbyD (vector<int> &nums, int divisor) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += ceil (double(nums[i]) / double(divisor));
        }
        return sum;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1; int maxi = INT_MIN; int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(nums[i], maxi);
        }
        int high = maxi;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (sumbyD(nums,mid) <= threshold) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};