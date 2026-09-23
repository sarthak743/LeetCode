//SC - O(1)

class Solution {
public:
    string reverseWords(string s) {
        //remove all space from behind
        while(s.back() == ' ')
            s.pop_back();

        reverse(s.begin(), s.end());

        //removes all spaces which were originally at front
        while(s.back() == ' ')
            s.pop_back();
        
        int i = 0, j = 0;
        //i --> for end of word
        //j --> for start of word
        while(i < s.size()){
            while(i < s.size() && s[i] != ' ')
                i++;

            //restores the reversed word    
            reverse(s.begin() + j, s.begin() + i);
            i++;

            //removes all extra spaces in btwn
            while(i < s.size() && s[i] == ' ')
                s.erase(i, 1);

            j=i;
        }

        return s;
    }
};