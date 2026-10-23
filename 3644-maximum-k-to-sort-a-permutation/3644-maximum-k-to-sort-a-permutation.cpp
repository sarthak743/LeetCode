//used hints by lc

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res = -1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == i)
                continue;
            res = res & nums[i];
        }

        if(res == -1)
            return 0;
        return res;
    }
};