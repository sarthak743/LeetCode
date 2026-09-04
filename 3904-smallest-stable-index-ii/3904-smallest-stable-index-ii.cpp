class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n, 0);
        int maxii = nums[0], minii = nums[n-1];

        mini[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < minii)
                minii = nums[i];
            mini[i] = minii;
        }

        for(int i = 0; i < n; i++){
            if(nums[i] > maxii)
                maxii = nums[i];
            if(maxii - mini[i] <= k)
                return i;
        }

        return -1;
    }
};