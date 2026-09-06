//since the condition says so 
//we can only pick cards from front and end
//so make all such possible subarray get their sum and return the max one 

//1 2 3 4 5 6 1
//lsum = 1 + 2
//rsum = 1      sum ==> 4

//for max sum
//lsum = 0
//rsum = 5 + 6 + 1  sum ==> 12

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0, r = n;
        int lsum = 0, rsum = 0;
        int res = 0;

        for(int i=1; i <= k; i++){
            lsum += cardPoints[l];
            l++;
        }

        while(l >= 0){
            res = max(res, lsum + rsum);

            l--;
            r--;
            if(l >= 0)
                lsum -= cardPoints[l];
            if(r >= 0)
                rsum += cardPoints[r];            
        }
        
        return res;
    }
};