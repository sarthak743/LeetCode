//similar to binary subarray with sum
//get count of subarray with at most k distinct (k = number of distinct in whole array)
//get count of subarray with at most k-1 distinct 
//return the difference of them

class Solution {
public:
    int maxcount(vector<int>& arr, int k){
        int l = 0, r = 0;
        int cnt = 0;
        unordered_map<int, int> mpp;

        while(r < arr.size()){
            mpp[arr[r]]++;

            while(mpp.size() > k){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0)
                    mpp.erase(arr[l]);
                l++;
            }

            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i=0; i < nums.size(); i++)
            mpp[nums[i]]++;
        
        int k = mpp.size();

        return maxcount(nums, k) - maxcount(nums, k-1);
    }
};