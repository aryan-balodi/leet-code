class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map <int,int> mpp;

        for (auto it : nums) {
            mpp[it]++;
        }

        int maxFreq = 0;

        for (const auto &x : mpp) {
            maxFreq = max(x.second, maxFreq);
        }

        int count = 0;

        for (const auto &y : mpp) {
            if (y.second == maxFreq) count++;
        }

        return count * maxFreq;

    }
};