class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = k;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] == i)
                i = i + k;
        }

        return i;
    }
};