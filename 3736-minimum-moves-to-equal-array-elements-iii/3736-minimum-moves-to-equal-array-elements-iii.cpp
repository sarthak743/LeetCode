class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0, maxi = *max_element(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
            res += (maxi - nums[i]);
        return res;
    }       
};