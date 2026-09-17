class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt = 0;
        for(int i=0; i < nums.size(); i++){
            int a = nums[i];
            while(a>0){
                if(a%10 == digit)
                    cnt++;
                a /= 10;
            }
        }

        return cnt;
    }
};