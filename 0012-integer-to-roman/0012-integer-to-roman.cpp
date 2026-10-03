class Solution {
public:
    string precedence(int k){
        if(k == 1)  return "I";
        if(k == 2)  return "V";
        if(k == 3)  return "X";
        if(k == 4)  return "L";
        if(k == 5)  return "C";
        if(k == 6)  return "D";
        if(k == 7)  return "M";

        return "";
    }

    string helper(int n, int p){
        string a = "";

        if(n >= 1 && n <= 3)
            while(n--)
                a += precedence(p);

        else if(n == 4)
            a += (precedence(p) + precedence(p+1));

        else if(n >= 5 && n <= 8){
            a += precedence(p+1);

            while(n>5){
                a += precedence(p);
                n--;
            }                
        }

        else
            a += (precedence(p) + precedence(p+2));

        return a;
    }


    string intToRoman(int num) {
        string res = "";

        int lastD = 0, mul = 1;

        while(num){
            lastD = (num % 10);

            if(lastD)
                res = helper(lastD, mul) + res;

            mul += 2;
            num /= 10;            
        }

        return res;
    }
};