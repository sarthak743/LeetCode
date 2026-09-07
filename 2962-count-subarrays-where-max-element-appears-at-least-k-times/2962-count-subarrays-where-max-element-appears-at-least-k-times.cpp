//find count of subarrays where maxi appears less than k times
//then subtract that count with total number of possible subarrays

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size();
        long long total = n * (n+1) / 2;
        int maxi = *max_element(nums.begin(), nums.end());

        int l = 0, r = 0;
        //gives count of subarray of where maxi appears less than k times
        long long n_posible = 0; 
        //keeps count of maxi in that subarray
        int cnt = 0;        

        while(r < n){
            if(nums[r] == maxi)
                cnt++;
            
            //if count of maxi becomes k 
            //shrink subarray
            while(cnt == k){
                if(nums[l] == maxi)
                    cnt--;
                l++;
            }

            n_posible += (r - l + 1);
            r++;
        }

        return total - n_posible;
    }
};