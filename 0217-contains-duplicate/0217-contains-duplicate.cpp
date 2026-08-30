class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int r = 0;
        map<int, int> mpp;

        while(r < nums.size()){
            if(mpp.find(nums[r]) != mpp.end())
                return true;

            mpp[nums[r]]++;

            r++;
        }

        return false;
    }
};