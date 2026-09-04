class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++)
            mpp[nums[i]]++;

        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res += mpp[nums[i]] - 1;
            mpp[nums[i]]--;
        }

        return res;
    }
};