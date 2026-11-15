class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int res = 0, n = nums.size();

        for(int i=0; i<n; i++){
            int aNd = nums[i], mini = nums[i];

            for(int j=i; j<n; j++){
                aNd = aNd & nums[j];
                if(nums[j] < mini)
                    mini = nums[j];

                if(aNd == mini)
                    res++;
            }
        }

        return res;
    }
};