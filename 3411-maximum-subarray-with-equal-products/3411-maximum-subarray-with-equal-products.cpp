#define ll long long

class Solution {
public:
    ll mod = 1e9+7;

    int maxLength(vector<int>& nums) {
        int n = nums.size(), res = 0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                ll l = nums[i], g = nums[i], p = nums[i];
                for(int k=i+1; k<=j ;k++){
                    p = (p*nums[k])%mod;
                    g = gcd(g, nums[k]);
                    l = lcm(l, nums[k]);
                }

                if(p == g*l)
                    res = max(res, j-i+1);
            }
        }

        return res;
    }
};

//product p can overflow even in long long
//as max is 10^100