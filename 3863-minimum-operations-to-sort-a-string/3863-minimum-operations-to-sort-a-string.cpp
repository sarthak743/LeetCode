//used hints

class Solution {
public:
    int minOperations(string s) {
        string a = s;
        sort(a.begin(), a.end());
        char mn = a[0];
        char mx = a[s.size() - 1];

        if(a == s)
            return 0;

        //if size 2 and not sorted then -1
        if(s.size() == 2)
            return -1;

        if(a[0] == s[0] || a[s.size()-1] == s[s.size() - 1])
            return 1;

        //if minimum and maximum arent in extreme point then 2
        for(int i=1; i<s.size()-1; i++)
            if(s[i] == mn || s[i] == mx)
                return 2;

        return 3;
    }
};