//move i till it hits odd and move j till it hits even
//if they hit someone like that swap them no matter what

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size();

        while (i < n && j < n) {
            while (i < n && nums[i] % 2 == 0)   i += 2;                

            while (j < n && nums[j] % 2 == 1)   j += 2;                

            if (i < n && j < n)     swap(nums[i], nums[j]);                
        }

        return nums;
    }
};