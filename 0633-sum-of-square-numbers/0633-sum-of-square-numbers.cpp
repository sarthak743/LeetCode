#define ll long long

class Solution {
public:
    bool judgeSquareSum(int c) {
        ll a = c, l = 0, h = sqrt(c);
        
        while(l <= h){
            ll sum = l*l + h*h;
            if(sum == a) 
                return true;
            
            else if(sum < a)
                l++;
            else
                h--;
        }

        return false;
    }
};