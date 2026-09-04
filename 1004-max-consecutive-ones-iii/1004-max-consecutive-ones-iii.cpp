//OPTIMAL
//TC - O(N)
//here we move l by one if z exceeds

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, z = 0;
        int res = 0;

        while(r < nums.size()){
            if(nums[r] == 0)
                z++;
            
            if(z > k){
                if(nums[l] == 0)
                    z--;
                l++;                    
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};