#define ll long long

class Solution {
public:
    bool sign(int a){
        return a > 0;
    }

    int divide(int dividend, int divisor) 
    {
        ll a = dividend, b = divisor;
        ll res = 0;

        if(!sign(a))
            a = -a;
        if(!sign(b))
            b = -b;

        // while(a >= b){
        //     ll minus = b;
        //     for(int i=0; i<=32; i++){
        //         if(a >= minus)
        //             minus *= 2;
        //         else
        //             break;
        //     }

        //     minus /= 2;
        //     a -= minus;
        //     res += (minus/b);
        // }

        //better code
        while(a >= b){
            int cnt = 0;
            while(a >= (b << (cnt + 1)))
                cnt++;

            a -= (b << cnt);
            res += (1 << cnt);
        }

        //edge case
        if(res == (1 << 31) && (sign(dividend) == sign(divisor)))
            return INT_MAX;

        if(res == (1 << 31) && (sign(dividend) != sign(divisor)))
            return INT_MIN;

        return (sign(dividend) == sign(divisor)) ? res : -res;
    }
};


// 22 / 3
// 3 * 7
// 3 * (2^2 + 2^1 + 2^0) == 21
// rem = 22 - 21 = 1 (less than 3 so no further iteration)

//take ll to handle edge case

//refer video