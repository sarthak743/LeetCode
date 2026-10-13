#define ll long long

class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums) {
        int n = nums.size(), i = 0;
        for(int i=0; i<n; i++)
            nums[i] = abs(nums[i]);

        sort(nums.begin(), nums.end());

        ll neg = 0, pos = 0;
        while(i<n){
            if(i<n/2)
                neg += (nums[i] * nums[i]);

            else
                pos += (nums[i] * nums[i]);

            i++;
        }

        return pos - neg;
    }
};