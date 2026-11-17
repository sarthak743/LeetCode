class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                //if(nums[j] == nums[i] && (j-i) != 1)
                  //  continue;

                sum = (nums[i] + nums[j]);
                for(int k=j+1; k<n; k++){
                    if(nums[k]<sum)
                        res++;
                    if(nums[k] > sum)
                        break;
                }
            }
        }

        return res;
    }
};