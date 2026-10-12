class Solution {
public:
    int flip(int a){
        if(a)
            return 0;
        return 1;
    }

    int minOperations(vector<int>& nums) {
        int cnt = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1)
                continue;

            if(nums[i] == 0 && i >= nums.size() - 2)
                return -1;

            nums[i] = flip(nums[i]);
            nums[i+1] = flip(nums[i+1]);
            nums[i+2] = flip(nums[i+2]);

            cnt++;
        }

        return cnt;
    }
};