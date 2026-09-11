//BETTER METHOD
//TC - O(logn)
//RECURSIVE

class Solution {
public:
    double power(double x, long long p){
        if(p == 0)  
            return 1;

        if(p % 2 == 0)
            return power(x*x, p/2);
        
        return x * power(x, p - 1);
    }

    double myPow(double x, int n) {
        long long p = n;

        if(p < 0)
            return 1 / power(x, -p);

        return power(x, p);
    }
};