//not great approach
//used given hints

class Solution {
public:
    int smallestNumber(int n, int t) {
        if(n % 10 == 0)     return n;

        int dup = n;   
        int prod = 1;       //takes product of all digits

        while(dup > 0){
            int lastD = dup % 10;
            prod *= lastD;
            dup /= 10;
        }

        if(prod % t == 0)   return n;   //if product is divisible then no need to process it more

        return smallestNumber(n+1, t);
    }
};