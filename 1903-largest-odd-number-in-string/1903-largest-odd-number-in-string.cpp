//iterate from last element
//pop everything until u get an odd
//pop_back() removes last element from string 

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size() - 1; i >= 0; i--){
            if(num[i] % 2 == 0)     num.pop_back();
            else    return num;
        }

        return "";
    }
};