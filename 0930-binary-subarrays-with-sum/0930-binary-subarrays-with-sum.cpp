//refer video
//couldnt understand most optimal solution 

class Solution {
public:
    int maxsum(vector<int> nums, int goal){
        if(goal < 0)
            return 0;

        int l = 0, r = 0;
        int sum = 0, cnt = 0;

        while(r < nums.size()){
            sum += nums[r];

            while(sum > goal){
                sum -= nums[l];
                l++;
            }

            //we take all possible string 
            //so we increment with length
            cnt += r - l + 1;
            r++;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return maxsum(nums, goal) - maxsum(nums, goal - 1);
    }
};