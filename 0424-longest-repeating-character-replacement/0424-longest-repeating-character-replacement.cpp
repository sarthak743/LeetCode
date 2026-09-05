//maxf = frequency of most frequent character
//minimum number of characters that can be changed = len(substring) - maxf 

//for every window have length and maxf 
//if their difference exceeds k
//move l till the diff becomes equal to k

//NO NEED to update maxf
//since after trimming substring (moving left) maxf decreases
//and lesser maxf wont satisfy condition
//ts also reduces TC


class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxlen = 0, maxf = 0;

        int hash[26] = {0};

        while(r < s.size()){
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);

            if((r - l + 1) - maxf > k){
                hash[s[l] - 'A']--;
                l++;                
            }

            maxlen = max(maxlen, r - l + 1);            
            r++;
        }

        return maxlen;
    }
};