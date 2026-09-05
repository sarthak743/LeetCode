//maxf = frequency of most frequent character
//minimum number of characters that can be changed = len(substring) - maxf 

//for every window have length and maxf 
//if their difference exceeds k
//move l till the diff becomes equal to k
//update maxf everytime l moves

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxlen = 0, maxf = 0;

        int hash[26] = {0};

        while(r < s.size()){
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);

            while((r - l + 1) - maxf > k){
                hash[s[l] - 'A']--;
                l++;

                //get maxf after moving l
                maxf = 0;
                for(int i = 0; i <= 25; i++)
                    maxf = max(maxf, hash[i]);
                
            }

            maxlen = max(maxlen, r - l + 1);            
            r++;
        }

        return maxlen;
    }
};