//have map of all characters from t and its freq
//iterate s and if we hit element which alr exists in map then do cnt++
//after that reduce the freq count of that character even if it dont exist in map originally
//at moment when cnt equals size of t update minlen and startindex 
//then we try to shrink substring by moving left
//when moving l increment freq of char at l and if it disturbs cnt break inner loop and move r

class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        int n = s.size(), m = t.size();
        int hash[256] = {0};

        //to return substring 
        int minlen = INT_MAX, startidx = -1;

        //help checks if substring has all characters from t
        int cnt = 0;
        
        //pre compute freq of char from t
        for(int i=0; i < m; i++)
            hash[t[i]]++;

        while(r < n){
            //if that char exists in t then cnt++
            if(hash[s[r]] > 0)
                cnt++;
            hash[s[r]]--;

            while(cnt == m){
                //update those only if we find 
                //string that got all char from t
                if((r - l + 1) < minlen){
                    startidx = l;
                    minlen = r - l + 1;
                }
                
                //minimize substring
                //increment freq 
                //and if it becomes positive then do cnt--
                hash[s[l]]++;
                if(hash[s[l]] > 0)
                    cnt--;
                l++;
            }

            r++;
        }

        //return substring only if we find such
        if(startidx != -1)  
            return s.substr(startidx, minlen);

        //else return empty string
        return "";
    }
};