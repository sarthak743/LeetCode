//used hints
class Solution {
public:
    int mod = 1e9 + 7;

    int rev(int a){
        int b = 0;

        while(a>0){
            int l = a % 10;
            b = b*10 + l;
            a /= 10;
        }

        return b;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size(), cnt = 0;

        for(int i=0; i<n; i++){
            nums[i] = (nums[i] - rev(nums[i])) % mod;
            cnt = (cnt + mpp[nums[i]]) % mod;
            mpp[nums[i]]++;
        }

        return cnt;
    }
};