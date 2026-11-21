//iterate all 32 bit position
//count number of 1 from all elements
//if count is divisible by 3 
//then that unique element dont hv set bit at that position

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        int num = 1;

        for(int i=0; i<32; i++){
            int sum = 0;
            for(int j=0; j<n; j++){
                if(nums[j] & num)
                    sum++;
            }

            if((sum % 3))
                res += num;

            num = num<<1;
        }

        return res;
    }
};