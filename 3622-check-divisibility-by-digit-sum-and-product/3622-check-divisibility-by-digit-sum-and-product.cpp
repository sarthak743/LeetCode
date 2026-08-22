class Solution {
public:
    bool checkDivisibility(int n) {
        int dup = n;

        int d_sum = 0;
        int d_prod = 1;
        int last = 0;

        while(dup > 0){
            last = dup % 10;
            
            d_sum += last;
            d_prod *= last;

            dup = dup / 10;
        }

        return !(n % (d_sum + d_prod));
    }
};