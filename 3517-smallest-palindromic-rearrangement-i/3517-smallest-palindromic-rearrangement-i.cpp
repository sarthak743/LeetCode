class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string a = "", b = "";

        for(int i=0; i<n/2; i++)
            a += s[i];

        sort(a.begin(), a.end());
        
        b = a;
        reverse(b.begin(), b.end());

        if(n%2)
            a += s[n/2];

        return a + b;
    }
};