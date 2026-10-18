class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int cnt=0;
        for(int i=1; i<nums.size(); i++)
            if(nums[i-1] == nums[i])
                cnt++;

        return cnt;
    }
};