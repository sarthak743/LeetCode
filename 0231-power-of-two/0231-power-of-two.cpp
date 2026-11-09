class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1)
            return true; 
            
        if(n < 0 || n % 2)
            return false;

        string a = "";
        while(n){
            a += to_string(n%2);
            n /= 2;
        }

        int ones = 0;
        for(int i=0; i<a.size(); i++)
            if(a[i] == '1')
                ones++;

        return ones == 1;
    }
};