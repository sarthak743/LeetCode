class Solution {
public:
    bool isvowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        
        return false;
    }

    int maxVowels(string s, int k) {
        unordered_map<char, int> mpp;
        int l = 0, r = 0;
        int maxnum = 0, num = 0;

        for(int i = 0; i < k; i++){
            if(isvowel(s[i]))  
                num++;
        }
            
        maxnum = num;
        
        for(int i = k; i < s.size(); i++){
            if(isvowel(s[i]))
                num++;
            if(isvowel(s[i-k]))
                num--;

            maxnum = max(maxnum, num);
        }

        return maxnum;
    }
};