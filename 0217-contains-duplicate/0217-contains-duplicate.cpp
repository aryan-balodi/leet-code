class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // for (int i = 0; i < nums.size(); i++) {
        //     int count = 0;
        //     for (int j = i; j < nums.size(); j++) {
        //         if (nums[i] == nums[j]) {
        //             count++;
        //         }
        //     }
        //     if (count > 1) return true;
        // }
        // return false;

        unordered_map<int,int> hash;

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        for (auto &it : hash) {
            if (it.second > 1) return true;
        }

        return false;


    }
};