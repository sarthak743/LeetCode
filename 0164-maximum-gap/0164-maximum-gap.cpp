class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int res = 0;
        if(nums.size() == 1)
            return 0;

        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++)
            res = max(res, nums[i] - nums[i-1]);

        return res;
    }
};