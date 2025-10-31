class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        constexpr int kMax = 100;
        vector<int> count(kMax + 1, 0);
        vector<int> ans;

        for (const int num : nums) {
            if (++count[num] == 2) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};