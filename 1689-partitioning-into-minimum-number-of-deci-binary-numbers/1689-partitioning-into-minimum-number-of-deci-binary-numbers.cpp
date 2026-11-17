class Solution {
public:
    int minPartitions(string n) {
        int lar = 0;
        for(int i=0; i<n.size(); i++)
            if((n[i] - '0') > lar)
                lar = n[i] - '0';
        
        return lar;
    }
};