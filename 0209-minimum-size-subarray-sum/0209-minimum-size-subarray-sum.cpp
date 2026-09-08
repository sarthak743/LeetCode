class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int sum = 0, minlen = INT_MAX;

        while(r < nums.size()){
            sum += nums[r];

            while(sum >= target){
                minlen = min(minlen, r - l + 1);
                sum -= nums[l];
                l++;
            }

            r++;
        }

        if(minlen == INT_MAX)
            return 0;
        return minlen;
    }
};