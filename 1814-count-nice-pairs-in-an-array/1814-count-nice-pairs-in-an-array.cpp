//used hints
class Solution {
public:
    int mod = 1e9 + 7;

    int rev(int a){
        string b = to_string(a);
        reverse(b.begin(), b.end());
        return stoi(b);
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size(), cnt = 0;

        for(int i=0; i<n; i++){
            nums[i] = (nums[i] - rev(nums[i])) % mod;
            cnt += (mpp[nums[i]] % mod);
            cnt %= mod;
            (mpp[nums[i]]++) % mod;
        }

        return cnt;
    }
};