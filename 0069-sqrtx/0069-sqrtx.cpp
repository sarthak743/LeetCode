class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;
        int answer;

        if(!x) return 0;

        while(low <= high){
            int mid = low + (high - low) / 2;       //as result might get overflowed
            
            if(1LL * mid * mid == x) return mid;

            if(1LL * mid*mid > x) high = mid - 1;
            else if(1LL * mid*mid < x){
                answer = mid;
                low = mid + 1;
            }
        }

        return answer;
    }
};