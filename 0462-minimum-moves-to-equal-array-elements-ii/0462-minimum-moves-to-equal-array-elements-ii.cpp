class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());

        int med = -1;       //median
        if(n % 2 != 0)  
            med = nums[n/2];
        else
            med = (nums[n/2] + nums[n/2 - 1]) / 2;

        for(int i=0; i<n; i++)
            res += abs(nums[i] - med);

        return res;
    }
};