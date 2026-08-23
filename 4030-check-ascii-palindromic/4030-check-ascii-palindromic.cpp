//brute
//get binary of characters from both ends
//if binary of one is reverse binary of other then check next
//if not then false

class Solution {
public:
    //helper to form binary of character
    string binary(char c){
        int n = c;
        string r = "";

        for(int i = 0; i < 8; i++){
            r += (n % 2);
            n /= 2;
        }

        reverse(r.begin(), r.end());
        return r;
    }

    bool isPalindromic(string s) {
        int i = 0, j = s.size() - 1;

        while(i <= j){
            string a = binary(s[i]);
            string b = binary(s[j]);
            reverse(b.begin(), b.end());

            if(a != b)
                return false;

            i++;
            j--;
        }

        return true;
    }
};