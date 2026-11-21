//take xor of both
//count set bits of xor

//10  ==>  1 0 1 0
//7  ==>   0 1 1 1 

//xor  ==>  1 1 0 1
//set bits  =  3  (result)

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xOr = start ^ goal;

        int res = 0;
        while(xOr){
            if(xOr % 2)
                res++;
            xOr /= 2;
        }

        return res;
    }
};