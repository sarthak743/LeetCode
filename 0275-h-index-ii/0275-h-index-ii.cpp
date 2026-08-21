//brute
//iterate from back
//if value (no of citations) are lesser than counter 
//then stop and return

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int count = 0;

        for(int i = n - 1; i >= 0; i--){
            if(citations[i] <= count)
                break;
            else 
                count++;
        }

        return count;
    }
};