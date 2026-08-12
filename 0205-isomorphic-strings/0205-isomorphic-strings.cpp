//egg   ->      1 2 2
//add   ->      1 2 2
//the pattern is same so they are isomorphic

//f11   ->      1 2 2
//b23   ->      1 2 3

//paper     ->      1 2 1 3 4
//title     ->      1 2 1 3 4

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Store the first-appearance order of each character.
        // Example: "egg" -> e=1, g=2 -> pattern becomes 122.
        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;

        // Start from 1 because 0 means the character hasn't been seen.
        int idx = 1;

        // These store the patterns generated for both strings.
        string a = "", b = "";

        // Build the pattern for s.
        for(int i = 0; i < s.size(); i++) {

            // New character -> give it a new ID.
            if(mpp1.find(s[i]) == mpp1.end()) {
                a += idx;
                mpp1[s[i]] = idx;
                idx++;
            }
            // Existing character -> reuse its previous ID.
            else
                a += mpp1[s[i]];
        }

        // IDs start from 1 again for t.
        idx = 1;

        // Build the pattern for t in the same way.
        for(int i = 0; i < s.size(); i++) {

            if(mpp2.find(t[i]) == mpp2.end()) {
                b += idx;
                mpp2[t[i]] = idx;
                idx++;
            }
            else
                b += mpp2[t[i]];
        }

        // Same pattern means the strings are isomorphic.
        return a == b;
    }
};