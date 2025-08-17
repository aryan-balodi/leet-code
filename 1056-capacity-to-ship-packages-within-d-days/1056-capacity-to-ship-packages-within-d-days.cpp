class Solution {
public:
    int daysReq(vector<int> &weights, int capacity) {
        long long load = 0; int days = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > capacity) {
                days = days + 1;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        long long low = *max_element(weights.begin(),weights.end());
        long long high = accumulate(weights.begin(),weights.end(),0);
        int ans = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            int noOfDays = daysReq(weights,mid);
            if (noOfDays <= days) {
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