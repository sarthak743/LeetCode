//sliding window
//update hashmap at every iteration


class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0;
        int result = 0;

        vector<int> freq(26, 0);    //character hashing

        while(r < s.size()){
            freq[s[r] - 'a']++;

            //move left until the current character' frequency is 2
            while(freq[s[r] - 'a'] > 2){
                freq[s[l] - 'a']--;
                l++;
            }

            result = max(result, r - l + 1);
            r++;
        }

        return result;
    }
};