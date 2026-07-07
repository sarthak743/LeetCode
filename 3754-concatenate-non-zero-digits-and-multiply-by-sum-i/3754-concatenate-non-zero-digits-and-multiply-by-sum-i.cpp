class Solution {
public:
    long long sumAndMultiply(int n) {
        string a = to_string(n);        //function to make variable into string
        string x = "";      //double quote for string, single for char
        int sum = 0;

        for(int i = 0; i < a.size(); i++){
            if(a[i] != '0')    x += a[i];
            sum += a[i] - '0';      //'0' is needed coz while accessing the elements of string ur actually accessing character
        }

        if(x == "")     return 0;

        long long num = stoll(x);       //make string to long long

        return num * sum;
    }
};