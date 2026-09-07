//whenever we tackle with number of subarrays
//we use that binary subarray with sum approach

class Solution {
public: 
    int maxcount(vector<int> arr, int a){
        int l = 0, r = 0;
        int cnt = 0;
        unordered_map<int, int> mpp;

        while(r < arr.size()){
            mpp[arr[r]]++;
            
            while(mpp.size() > a){
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

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return maxcount(nums, k) - maxcount(nums, k-1);    
    }
};  