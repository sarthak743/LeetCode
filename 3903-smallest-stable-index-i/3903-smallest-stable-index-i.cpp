class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = nums[0], mini = *min_element(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxi)
                maxi = nums[i];
            mini = *min_element(nums.begin() + i, nums.end());
            if(maxi - mini <= k)
                return i;
        }
        return -1;
    }
};