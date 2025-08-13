class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary search bounds
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canFinish(piles, h, mid)) {
                right = mid; // Try slower speed
            } else {
                left = mid + 1; // Need faster speed
            }
        }
        
        return left;
    }
    
private:
    bool canFinish(vector<int>& piles, int h, int k) {
        long long hours = 0;
        
        for (int pile : piles) {
            // Calculate hours needed for this pile
            // Use ceiling division: (pile + k - 1) / k
            hours += (pile + k - 1) / k;
            
            // Early termination if we exceed h hours
            if (hours > h) {
                return false;
            }
        }
        
        return hours <= h;
    }
};
