class Solution {
public:
    bool canAliceWin(int n) {
        int a = 1, b = 0, x = 10;

        while(n>-1){
            if(a && n >= x){
                n -= x;
                x--;
                a = 0;
                b = 1;
            }
            else
                return false;

            if(b && n >= x){
                n -= x;
                x--; 
                b = 0;
                a = 1;
            }
            else
                return true;
        }

        return true;
    }
};