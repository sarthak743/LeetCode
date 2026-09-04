//OPTIMAL
//expels the worst case of 2N

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int l = 0, r = 0;
        int res = 0;

        while(r < fruits.size()){
            mpp[fruits[r]]++;

            if(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++; 
            }

            //update result only if it satisfies condition
            if(mpp.size() <= 2)
                res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};