class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++)
            mpp[nums[i]]++;

        int res = 0;
        for(auto i : mpp)
            if(i.second == 2)
                res ^= i.first;

        return res;
    }
};