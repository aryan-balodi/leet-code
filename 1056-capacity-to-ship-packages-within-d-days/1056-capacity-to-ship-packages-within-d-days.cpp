class Solution {
public:
    bool canShip(const vector<int>& weights, int days, int capacity) {
        int current_load = 0;
        int required_days = 1;
        for (int weight : weights) {
            if (current_load + weight > capacity) {
                required_days++;
                current_load = 0;
            }
            current_load += weight;
            if (required_days > days) {
                return false;
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
