//similar to 438

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<char> h2 (26, 0);
        vector<char> h1 (26, 0);

        for(int i=0; i < s1.size(); i++)
            h1[s1[i] - 'a']++;

        int l = 0, r = 0;
        int k = s1.size();
        while(r < s2.size()){
            h2[s2[r] - 'a']++;

            if((r-l+1) > k){
                h2[s2[l] - 'a']--;
                l++;
            }

            if(h1 == h2)
                return true;
            r++;
        }

        return false;
    }
};