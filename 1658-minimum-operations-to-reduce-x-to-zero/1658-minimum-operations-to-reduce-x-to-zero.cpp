//find length of largest subarray with sum total - x
//return (n - length of that subarray) if such subarray is found 

//no need to find pref suff for this approach
//they actually hinder it

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0, n = nums.size();

        for(int i=0; i < n; i++)
            total += nums[i];

        //if sum is less obv we cant get x any how
        if(total < x)
            return -1;

        int l = 0, r = 0, sum = 0, len = INT_MIN;
        while(r < n){
            sum += nums[r];

            while(sum > total - x){
                sum -= nums[l];
                l++;
            }

            if(sum == total - x)
                len = max(len, r - l + 1);
            r++;
        }

        if(len != INT_MIN)
            return n - len;

        return -1;
    }
};