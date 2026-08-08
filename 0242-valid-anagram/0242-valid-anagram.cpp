//first we will compare the size of the strings if yes then move forward no then false
//we will use hashing twice bcecause of two different strings
//further we will compare these two if same then its anagram
//while comparing the loop should go from a to z to check the number of alphabets present in those maps
//while hashing we used <char, int> so the number of characters is stored in the map 
//Ex : {{a, 3}, {n, 1}, {g, 1}, {r, 1}, {m, 1}} --> for word "anagram" also for "nagaram" since the maps are same they are anagram

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size()!=t.size())
        {
            return false;
        }

        int n = s.size();
        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;

        for(int i=0; i<n; i++)
        {
            mpp1[s[i]]++;     
            mpp2[t[i]]++;  
        }

        for(char j='a'; j<='z'; j++) 
        {
            if(mpp1[j]!=mpp2[j])
            {
                return false;
            }
        }
        return true;
    }
};