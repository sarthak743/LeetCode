//erase();
//s = "abcd";
//s.erase(2) --> output : s = "ab"
//everything from s[2] till end gone


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        if(strs.size() == 0) return s;      
        if(strs.size() == 1) return strs[0];

        //if empty string exists then its the answer 
        for(int i = 0; i < strs.size(); i++){
            if(strs[i] == "") return s;
        }

        int i = 0;
        while (i < min ( strs[0].size(), strs[1].size() ) ){
            if(strs[0][i] != strs[1][i])    break;
            s += strs[0][i];
            i++;
        }

        for(int i = 2; i < strs.size(); i++){
            int j = 0;
            while(j < min (s.size(), strs[i].size() ) ){
                //checks if character is same or not, if not then everything from that character till end of s will get erased-
                if(s[j] != strs[i][j]){
                    s.erase(j);     //this will remove (erase) characters from s[j] till the end
                    break;
                }

                j++;
            }

            //for that fucking edge case
            if(s.empty())   return "";

            //when strs[i] is shorter than s this if will help
            if(j == strs[i].size() && strs[i].size() < s.size()){
                s.erase(strs[i].size());
            }
            //this should outside of while loop coz this condition cant be checked inside of while loop
        }

        return s;
    }
};