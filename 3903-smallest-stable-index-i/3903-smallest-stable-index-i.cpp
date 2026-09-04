class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n,0);      //storing the min value of every suffix

        mini[n-1] = nums[n-1];
        int minii = mini[n-1];
        for(int i = n-2; i >= 0; i--){
            minii = min(minii, nums[i]);
            mini[i] = minii;
        }

        int maxi = nums[0];
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            if(maxi - mini[i] <= k)
                return i;
        }

        return -1;
    }
};