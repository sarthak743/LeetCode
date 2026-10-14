class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";

        while(num--){
            if(sum < 10){
                res += to_string(sum);
                sum = 0;
            }

            else{
                res += "9";
                sum -= 9;
            }
        }

        if(sum)
            return "";

        return res;
    }
};