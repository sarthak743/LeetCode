//BETTER METHOD
//TC - O(logn)

class Solution {
public:
    double myPow(double x, int n) {
        long long a = n;
        if(n < 0)
            a *= -1;
        double res = 1;

        while(a > 0){
            if(a % 2 == 0){
                x *= x;
                a /= 2;
            }

            else{
                res *= x;
                a--;
            }
        }

        if(n < 0)
            return 1 / res;
        
        return res;
    }
};