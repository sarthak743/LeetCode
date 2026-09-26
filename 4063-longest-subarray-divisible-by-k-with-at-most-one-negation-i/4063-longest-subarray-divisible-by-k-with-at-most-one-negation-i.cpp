//to find that element whose negatate will make sum divisible by k
//we make array of size k with all false
//and make that position true if find element with that remainder

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, res = 0;
        
        for(int i=0; i<n; i++){
            sum = 0;
            vector<bool> arr(k, false);
            
            for(int j=i; j<n; j++){
                sum += nums[j];

                int x = (2*nums[j]) % k;
                //to handle negative
                if(x<0)
                    x += k;
                arr[x] = true;
                
                int a = sum % k;
                if(a<0)
                    a += k;

                //if subarray has sum which is divisible by k
                if(!a)
                    res = max(res, j-i+1);

                //to find such element whose negatate can make sum of subarray divisible by k
                //if it exists in subarray then yes
                if(arr[a])
                    res = max(res, j-i+1);
            }
        }

        return res;
    }
};