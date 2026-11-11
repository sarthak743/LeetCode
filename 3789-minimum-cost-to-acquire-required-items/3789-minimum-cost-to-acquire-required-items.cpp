#define ll long long

class Solution {
public:
    ll minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll res = 0;
        ll mini = min(need1, need2);
        ll mincost = min(costBoth, cost1 + cost2);
        ll rem = max(need1, need2) - min(need1, need2);

        res += (mincost * mini);

        if(need1 > need2){
            ll to_add = min(costBoth, cost1);

            res += (rem * to_add);
        }

        else{
            ll to_add = min(costBoth, cost2);

            res += (rem * to_add);
        }

        return res;
    }
};