//desc is hell
//get sum of customer who were satisfied = satis
//get sliding window of size minutes
//keep sum of customers who werent satisfied originally in that window = lost
//return sum of max lost + satis

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n= customers.size();
        int l = 0, r = 0, k = minutes;
        int satis = 0, lost = 0, maxlost = 0;

        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0)
                satis += customers[i];
        }

        for(int i=0; i < k; i++){
            if(grumpy[i])
                lost += customers[i];
        }

        maxlost = lost;

        for(int i=k; i < n; i++){
            if(grumpy[i])
                lost += customers[i];
            if(grumpy[i-k])
                lost -= customers[i-k];

            maxlost = max(maxlost, lost);
        }

        return satis + maxlost;
    }
};