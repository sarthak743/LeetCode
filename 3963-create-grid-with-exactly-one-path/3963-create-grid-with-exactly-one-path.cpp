class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        string a = "", b = "";
        for(int i=0; i<n; i++)
            a += ".";
        res.push_back(a);
        for(int i=0; i<n-1; i++)
            b += "#";
        b += ".";
        for(int i=1; i<m; i++)
            res.push_back(b);
        return res;
    }
};