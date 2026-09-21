class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        int n = nums.size(), sum = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    sum = nums[i] + nums[j] + nums[k];
                    if(abs(target - sum) < abs(target - res))
                        res = sum;
                }
            }
        }

        return res;
    }
};