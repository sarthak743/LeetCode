class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(!k)
            return false;

        int l = 0, r = 0;
        unordered_map<int, int> mpp;

        while(r < nums.size()){ 
            mpp[nums[r]]++;

            while(r - l > k){
                mpp[nums[l]]--;
                l++;
            }                

            if(mpp[nums[r]] > 1)
                return true;
            
            r++;
        }

        return false;
    }
};