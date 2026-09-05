class Solution {
public:
    long long coloredCells(int n) 
    {
        long long a = n;
        return a*a + (a-1) * (a-1);      
    }
};