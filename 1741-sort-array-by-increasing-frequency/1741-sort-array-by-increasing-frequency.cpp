class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int &num : nums)
            ++freq[num];
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b])
                return a > b; // for same frequency: higher number first
            return freq[a] < freq[b]; // increasing frequency
        });
        return nums;
    }
};
