//SLIDING WINDOW
//quite similar to binary subarray with sum

//to get total count of such subarrays
//increment cnt with length of subarray

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l = 0, r = 0;
        long long sum = 0, cnt = 0;

        while(r < nums.size()){
            sum += nums[r];

            while(sum * (r - l + 1) >= k){
                sum -= nums[l];
                l++;
            }

            cnt += (r - l + 1);
            r++;
        }

        return cnt;        
    }
};