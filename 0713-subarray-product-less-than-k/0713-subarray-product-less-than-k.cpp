class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0;
        double prod = 1;
        int cnt = 0;

        while(r < nums.size()){
            //skip all non ones 
            //for k = 1
            if(k == 1 && nums[r] != 1){
                r++;
                l++;
            }

            else{
                prod *= nums[r];

                while(l < nums.size() && prod >= k){    
                    prod /= nums[l];
                    l++;
                }

                cnt += (r - l + 1);
                r++;
            }
        }

        return cnt;
    }
};