class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int preSum = nums[0];
        int i = 1;

        while(i < nums.size() && nums[i] == nums[i-1] + 1){
            preSum += nums[i];
            i++;
        }

        sort(nums.begin(), nums.end());
        i = 0;
        while(i < nums.size()){
            if(nums[i] == preSum)
                preSum++;
            i++;
        }

        return preSum;
    }
};