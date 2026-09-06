//checking everytime subarray if it has distinct
//will surely hit tle

//have hashmap working like hashset
//like make window of size k and get sum of it and update map likewise
//if window has distinct then only update maxsum
//move window from both side, update sum and map too
 

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0, r = 0;
        long long sum = 0, maxsum = 0;
        unordered_map<int, int> mpp;
        
        for(int i=1; i < k; i++){
            sum += nums[r];
            mpp[nums[r]]++;
            r++;
        }

        while(r < nums.size()){
            sum += nums[r];
            mpp[nums[r]]++;

            if(mpp.size() == k)
                maxsum = max(maxsum, sum);
            
            sum -= nums[l];
            mpp[nums[l]]--;
            //this map should work like set
            if(mpp[nums[l]] == 0)
                mpp.erase(nums[l]);
            r++;
            l++;
        }

        return maxsum;
    }
};