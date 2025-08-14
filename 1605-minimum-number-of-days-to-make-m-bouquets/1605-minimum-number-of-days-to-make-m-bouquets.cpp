class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // If we need more flowers than available, return -1
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }
        
        // Binary search bounds
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Check if we can make m bouquets by day 'mid'
            int bouquets = 0;
            int consecutive = 0;
            
            for (int bloom : bloomDay) {
                if (bloom <= mid) {
                    consecutive++;
                    // If we have k consecutive bloomed flowers, make a bouquet
                    if (consecutive == k) {
                        bouquets++;
                        consecutive = 0;
                    }
                } else {
                    consecutive = 0;
                }
            }
            
            if (bouquets >= m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
