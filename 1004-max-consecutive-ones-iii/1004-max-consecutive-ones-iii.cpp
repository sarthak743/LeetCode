//sliding window
//have count of zeroes in window
//if it exceeds k
//move left until its equal to k
//update res at every moment

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, z = 0;
        int res = 0;

        while(r < nums.size()){
            if(z <= k && nums[r] == 1)
                r++;

            else if(nums[r] == 0){
                z++;
                r++;
            }                

            while(z > k){
                if(nums[l] == 0)
                    z--;
                l++;
            }                

            res = max(res, r - l);
        }

        return res;
    }
};