class Solution {
public:
    void add(int sum, int to_add, int carry){
        
    }

    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int sum = 0, to_add = 0, carry = 0;
        string result = "";

        while(i >= 0 && j >= 0){
            sum = (a[i] - '0') + (b[j] - '0') + carry;
            if(sum == 1){
                to_add = 1;
                carry = 0;
            }

            else if(sum == 2){
                to_add = 0;
                carry = 1;
            }

            else if(sum == 3){
                to_add = 1;
                carry = 1;
            }

            else if(sum == 0){
                to_add = 0;
                carry = 0;
            }

            result += to_string(to_add);    
            
            i--;
            j--;
        }

        while(i >= 0){
            sum = (a[i] - '0') + carry;
            if(sum == 1){
                to_add = 1;
                carry = 0;
            }

            else if(sum == 2){
                to_add = 0;
                carry = 1;
            }

            else if(sum == 3){
                to_add = 1;
                carry = 1;
            }

            else if(sum == 0){
                to_add = 0;
                carry = 0;
            }

            result += to_string(to_add);    
            
            i--;
        }

        while(j >= 0){
            sum = (b[j] - '0') + carry;
            if(sum == 1){
                to_add = 1;
                carry = 0;
            }

            else if(sum == 2){
                to_add = 0;
                carry = 1;
            }

            else if(sum == 3){
                to_add = 1;
                carry = 1;
            }

            else if(sum == 0){
                to_add = 0;
                carry = 0;
            }

            result += to_string(to_add);    
            
            j--;
        }

        if(carry) result += to_string(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};