class Solution {
public:
    int noOfSubArrays(vector<int> &nums, long long sum) {
        int subArrays = 1;
        long long current_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (current_sum + nums[i] <= sum) {
                current_sum += nums[i];
            }
            else {
                subArrays += 1;
                current_sum = nums[i];
            }
        }
        return subArrays; 
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (noOfSubArrays(nums, mid) > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return (int)low;
    }
};

