//prefix sum approach
//get prefix sum upto i
//if sum is odd inc res by number of even sum subarrays before i
//also inc odd by one
//vice versa for even

//even = 1  (initially)
//coz before first element the subarray before it is empty
//whose sum is 0 which is even

#define ll long long

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        ll res = 0, prefix = 0, mod = 1e9+7;
        int n = arr.size(), even  = 1, odd = 0;

        for(int i=0; i<n; i++){
            prefix += arr[i];

            if(prefix%2 == 0){
                res += odd;
                even++;
            }
                
            else{
                res += even;
                odd++;
            }
        }
        
        res = res % mod;
        return (int)res;
    }
};