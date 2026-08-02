//similar to KOKO banana problem
//Binary Search
//TC - O(N * log(maxi))

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = *max_element(nums.begin(), nums.end());
        int low = 1, high = maxi;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int sum = 0;

            for(int j = 0; j < nums.size(); j++){
                sum += ceil((double) nums[j] / mid); 
            }

            if(sum <= threshold)    high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};