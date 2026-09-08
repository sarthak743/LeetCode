class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = 0;
        double sum = 0, maxsum = INT_MIN;

        for(int i = 0; i < k; i++){
            sum += nums[r];
            r++;
        }

        maxsum = max(maxsum, sum);

        while(r < nums.size()){
            sum += nums[r];
            sum -= nums[l];
            maxsum = max(maxsum, sum);

            l++;
            r++;            
        }

        return maxsum / k;
    }
};