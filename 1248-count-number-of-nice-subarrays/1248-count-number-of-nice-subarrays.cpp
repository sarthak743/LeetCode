//similar to max sum of binary array 

class Solution {
public:
    int maxcount(vector<int>& arr, int k){
        int n = arr.size();
        int l = 0, r = 0;
        int cnt = 0, a = 0;

        while(r < n){
            if(arr[r] % 2 == 1)
                a++;

            while(a > k){
                if(arr[l] % 2 == 1)
                    a--;
                l++;
            }

            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return maxcount(nums, k) - maxcount(nums, k-1);    
    }
};