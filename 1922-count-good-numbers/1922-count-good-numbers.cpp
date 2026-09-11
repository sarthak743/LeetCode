//for any n
//answer == 5*4*5*4*5*4... (till n digits)
//as there are 5 evens (0, 2, 4, 6, 8)
//as there are 4 primes (2, 3, 5, 7)
//take modulus with mod at every step so that we dont get runtime error (no overflow happens)

class Solution {
public:
    int mod = 1e9 + 7; 
    long long power(long long x, long long p){
        if(p == 0)
            return 1;

        if(p % 2 == 0)
            return (power((x * x) % mod, p / 2)) % mod;

        return (x * power(x, p - 1)) % mod;
    }

    int countGoodNumbers(long long n) {
        if(n % 2 == 0)
            return (power(5, n / 2) * power(4, n / 2)) % mod;
        
        return (power(5, n / 2 + 1) * power(4, n / 2)) % mod;
    }
};