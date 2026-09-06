//constant size window
//get minimum sum of such window and subtract it from totalsum
//return the difference

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int tsum = 0, sum = 0;
        int res = 0;
        for(int i = 0; i < n; i++)
            tsum += cardPoints[i];

        //window size
        int len = n - k;
        if(len == 0)
            return tsum;

        int l = 0, r = 0;
        for(int i=1; i<len; i++){
            sum += cardPoints[r];
            r++;
        }

        while(r < n){
            sum += cardPoints[r];
            res = max(res, tsum - sum);
            sum -= cardPoints[l];
            l++;
            r++;
        }

        return res;
    }
};