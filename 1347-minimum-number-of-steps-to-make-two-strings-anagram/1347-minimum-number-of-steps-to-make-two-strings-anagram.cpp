class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;
        int count = 0;

        for(int i = 0; i < s.size(); i++){
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }

        for(char c = 'a'; c <= 'z'; c++){
            count += max(0, mpp1[c] - mpp2[c]);     //update count only when t is missing some copies of that character
        }

        return count;
    }
};